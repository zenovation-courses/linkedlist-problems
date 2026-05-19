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

void splitAlternately( struct Node* head,
            struct Node** listA, struct Node** listB){

    if( head == NULL || head->next == NULL )
        return;
    
    *listA = head;
    *listB = head->next;
    
    struct Node* curr = head->next;
    struct Node* prev = head;
    
    while( curr ){
        prev->next = curr->next;
        prev = curr;
        curr = curr->next;
    }
    return;  
}

int main(){
    
    struct Node* head = NULL,
            *listA = NULL, *listB = NULL;
    
    head = addNode(head, 44);
    head = addNode(head, 2);
    head = addNode(head, 17);
    head = addNode(head, 8);
    head = addNode(head, 14);
    head = addNode(head, 4);
    head = addNode(head, 75);
    
    printLList(head);
    splitAlternately(head, &listA, &listB);
    printLList(listA);
    printLList(listB);

}
