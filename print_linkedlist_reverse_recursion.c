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

void printReverse(struct Node* head){
    
    if( head == NULL )
        return;
    
    printReverse(head->next);
    
    printf("%d  ", head->data);
}

int main(){
    
    struct Node* head = NULL;
    
    head = addNode(head, 2);
    head = addNode(head, 23);
    head = addNode(head, 17);
    head = addNode(head, 8);
    head = addNode(head, 9);
    
    printLList(head);
    printReverse(head);

}
