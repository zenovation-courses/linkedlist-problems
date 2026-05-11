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

struct Node* moveLastToFront(struct Node* head){
    
    if( head == NULL || head->next == NULL )
        return head;
        
    struct Node* prev = NULL, *current = head;
    
    while( current->next != NULL ){
        prev = current;
        current = current->next;
    }
    
    prev->next = NULL;
    current->next = head;
    
    return current;
}

int main(){
    
    struct Node* head = NULL;
    
    head = addNode(head, 12);
    head = addNode(head, 76);
    head = addNode(head, 47);
    head = addNode(head, 7);
    head = addNode(head, 17);
    
    printLList(head);
    head = moveLastToFront(head);
    printLList(head);

}
