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

void deleteAlternateNodes(struct Node* head){
    
    if ( !head )
        return;
    
    struct Node* prev = head, *current = head->next;
    
    while( prev && current ){
        prev->next = current->next;
        free(current);
        prev = prev->next;
        if ( prev )
            current = prev->next;
    }
}

int main(){
    
    struct Node* head = NULL;
    
    head = addNode(head, 12);
    head = addNode(head, 76);
    head = addNode(head, 47);
    head = addNode(head, 7);
    head = addNode(head, 17);
    
    printLList(head);
    deleteAlternateNodes(head);
    printLList(head);
}
