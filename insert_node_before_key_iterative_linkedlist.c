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

struct Node* insertBeforeNode(struct Node* head, 
                            int key, int num){
                                
    if( !head )
        return NULL;
        
    if( head->data == key ){
        struct Node* newNode = 
            (struct Node*)malloc(sizeof(struct Node));
        newNode->data = num;
        newNode->next = head;
        return newNode;
    }
    
    struct Node* prev = NULL, *curr = head;
    
    while( curr && curr->data != key ){
        prev = curr;
        curr = curr->next;
    }
    
    if( !curr )
        return head;
        
    struct Node* newNode =
        (struct Node*)malloc(sizeof(struct Node));
    newNode->data = num;
    newNode->next = curr;
    prev->next = newNode;
    return head;
                                
}


int main(){
    
    struct Node* head = NULL;
    
    head = addNode(head, 12);
    head = addNode(head, 4);
    head = addNode(head, 47);
    head = addNode(head, 7);
    head = addNode(head, 17);
    
    printLList(head);
    head = insertBeforeNode(head, 47, 23);
    printLList(head);

}
