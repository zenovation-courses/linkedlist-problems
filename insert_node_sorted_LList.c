#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

void printLList(struct Node* head){
    while(head){
        printf("%d  ", head->data);
        head = head->next;
    }
    printf("\n");
}

struct Node* addNode(struct Node* head, int num){
    
    struct Node* newNode = 
        (struct Node*)malloc(sizeof(struct Node));
    newNode->data = num;
    newNode->next = head;
    
    return newNode;
}

struct Node* insertNodeinSortedLL
        ( struct Node* head, int newNodeData ){

    struct Node* newNode = 
        (struct Node* )malloc(sizeof(struct Node));
    newNode->data = newNodeData;
    
    if ( head == NULL || newNodeData < head->data ){
        newNode->next = head;
        return newNode;
    }
    
    struct Node* curr = head;
    
    while(curr->next && newNodeData > curr->next->data)
        curr = curr->next;
    
    newNode->next = curr->next;
    curr->next = newNode;
    
    return head;
}

int main(){
    
    struct Node* head = NULL;
    
    head = addNode(head, 44);
    head = addNode(head, 23);
    head = addNode(head, 17);
    head = addNode(head, 8);
    head = addNode(head, 4);
    
    printLList(head);
    head = insertNodeinSortedLL(head, 11);
    printLList(head);

}
