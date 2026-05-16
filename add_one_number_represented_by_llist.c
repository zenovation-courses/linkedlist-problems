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

struct Node* reverseLL(struct Node* head){
    
    struct Node* prev = NULL, *temp = head;
    
    while( head ){
        temp = head->next;
        head->next = prev;
        prev = head;
        head = temp;
    }
    
    return prev;
    
}

struct Node* addOneEachNode(struct Node* head){
    
    struct Node* prev = NULL, *current = head;
    int carry = 1;
    
    while ( current ){
        
        int sum = carry + current->data;
        carry = sum / 10;
        current->data = sum % 10;
        prev = current;
        current = current->next;
        
    }
    
    if ( carry ){
        prev->next = 
            (struct Node*)malloc(sizeof(struct Node));
        prev->next->data = carry;
        prev->next->next = NULL;
    }
    
    return head;
    
}

struct Node* addOne(struct Node* head){
    
    head = reverseLL(head);
    
    head = addOneEachNode(head);
    
    head = reverseLL(head);
    
    return head;
    
}

int main(){
    
    struct Node* head = NULL;
    
    head = addNode(head, 9);
    head = addNode(head, 9);
    head = addNode(head, 9);
    head = addNode(head, 9);
    
    printLList(head);
    head = addOne(head);
    printLList(head);
}
