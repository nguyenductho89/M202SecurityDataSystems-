//
//  linklistTest.c
//  linklistTest
//
//  Created by nguyen.duc.tho on 3/29/18.
//  Copyright © 2018 Nguyễn Đức Thọ. All rights reserved.
//

/* Doubly Linked List implementation */
#include<stdio.h>
#include<stdlib.h>
typedef unsigned char BYTE;
struct Node  {
    BYTE block[16];
    struct Node* next;
    struct Node* prev;
};
struct Node* head;// global variable - pointer to head node.

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


//Prints all the elements in linked list in forward traversal order
//void Print() {
//    struct Node* temp = head;
//    printf("Forward: ");
//    while(temp != NULL) {
//        printf("%d ",temp->data);
//        temp = temp->next;
//    }
//    printf("\n");
//}

//Prints all elements in linked list in reverse traversal order.
//void ReversePrint() {
//    struct Node* temp = head;
//    if(temp == NULL) return; // empty list, exit
//    // Going to last Node
//    while(temp->next != NULL) {
//        temp = temp->next;
//    }
//    // Traversing backward using prev pointer
//    printf("Reverse: ");
//    while(temp != NULL) {
//        printf("%d ",temp->data);
//        temp = temp->prev;
//    }
//    printf("\n");
//}

int main() {
    
    /*Driver code to test the implementation*/
     //head = NULL; //  // empty list. set head as NULL.
    BYTE aNode[16];
    for (int i = 0; i<16; i++) {
        aNode[i] = (BYTE)i;
    }
    BYTE bNode[16];
    for (int i = 0; i<16; i++) {
        bNode[i] = (BYTE)(16-i);
    }
    // Calling an Insert and printing list both in forward as well as reverse direction.
    InsertAtTail(aNode);
    //Print(); ReversePrint();
    InsertAtTail(bNode);
    //Print(); ReversePrint();
    //InsertAtHead(6);
    //Print(); ReversePrint();
    //InsertAtTail(8);
    //Print(); ReversePrint();
    
}
