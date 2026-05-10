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

void kthNodeFromEnd(struct Node* head, int k){
    
    if ( !head ){
        printf("Linked List is empty\n");
        return;
    }
    
    struct Node* behind = head, *ahead = head;
    
    while(--k){
        ahead = ahead->next;
        
        if ( !ahead ){
            printf("Cannot get to kth node from end. List is short");
            return;
        }
    }
    
    while( ahead->next != NULL ){
        behind = behind->next;
        ahead = ahead->next;
    }
    
    printf("kth node from the end: %d\n", behind->data);
    return;
    
}

int main(){
    
    struct Node* head = NULL;
    
    head = addNode(head, 12);
    head = addNode(head, 76);
    head = addNode(head, 47);
    head = addNode(head, 7);
    head = addNode(head, 17);
    
    printLList(head);
    kthNodeFromEnd(head, 9);

}
