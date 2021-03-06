//
//  readHexFromFileTEst.c
//  aes-ecb
//
//  Created by nguyen.duc.tho on 3/29/18.
//  Copyright © 2018 Nguyễn Đức Thọ. All rights reserved.
//

#include<stdio.h>
#include<stdlib.h>
#include"Helper.h"
// MARK: - Link list
struct Node  {
    BYTE block[16];
    struct Node* next;
    struct Node* prev;
};
struct Node* head; // global variable - pointer to head node.
//Creates a new Node and returns pointer to it.
struct Node* GetNewNode(BYTE block[16]) {
    struct Node* newNode
    = (struct Node*)malloc(sizeof(struct Node));
    for (int i = 0; i<16; i++) {
        newNode->block[i] = block[i];
    }
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

//Inserts a Node at head of doubly linked list
void InsertAtHead(BYTE block[16]) {
    struct Node* newNode = GetNewNode(block);
    if(head == NULL) {
        head = newNode;
        return;
    }
    head->prev = newNode;
    newNode->next = head;
    head = newNode;
}

//Inserts a Node at tail of Doubly linked list
void InsertAtTail(BYTE block[16]) {
    struct Node* temp = head;
    struct Node* newNode = GetNewNode(block);
    if(head == NULL) {
        head = newNode;
        return;
    }
    while(temp->next != NULL) temp = temp->next; // Go To last Node
    temp->next = newNode;
    newNode->prev = temp;
}

int main()
{
    FILE *fp;
    fp = fopen("padding16copy", "rb");
    //fp = fopen("padding16", "rb");
    
    if(fp == NULL)
    {
        printf("Error opening file\n");
        exit(1);
    }
    
    BYTE aByte;
    BYTE block[16];
    int i = 0;
    int numberOfBlock = 0;
    while( fread(&aByte, sizeof(aByte), 1, fp) )
    {
        block[i] = aByte;
        i++;
        if (i==16) {
            i = 0;
            InsertAtTail(block);
            numberOfBlock++;
        }
    }
    //Padding for the last block
    int lastBlockLength = i;
    int padding = 16 - lastBlockLength;
    int interator = padding;
    if (padding > 0) {
        while (interator>0) {
            block[16-interator] = (BYTE)(padding);
            interator--;
        }
    } else if(padding == 0) {
        BYTE paddingBlock[16];
        for (int i = 0; i<16; i++) {
            paddingBlock[i] = (BYTE)16;
        }
        InsertAtTail(paddingBlock);
    }else {
        perror("Check create block function");
    }
//    for (int j = 0; j<16; j++) {
//        printf("%x\n",block[j]);
//    }
    struct Node* temp = head;
        while(temp != NULL) {
            for (int i = 0; i<16; i++) {
                printf("%x ",temp->block[i]);
            }
            printf("\n");
            temp = temp->next;
        }
        printf("\n");
    
    
    
    fclose(fp);
    return 0;
}

