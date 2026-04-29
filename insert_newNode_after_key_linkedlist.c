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

void insertAfterNode(struct Node* head, 
                            int key, int num){

    if ( !head )
        return;
        
    while( head && head->data != key ){
        head = head->next;
    }
    
    if( !head )
        return;
    
    struct Node* newNode =
            (struct Node*)malloc(sizeof(struct Node));
    newNode->data = num;
    newNode->next = head->next;
    head->next = newNode;
    return;
                             
}

int main(){
    
    struct Node* head = NULL;
    
    head = addNode(head, 12);
    head = addNode(head, 4);
    head = addNode(head, 47);
    head = addNode(head, 7);
    head = addNode(head, 17);
    
    printLList(head);
    insertAfterNode(head, 99, 23);
    printLList(head);

}
