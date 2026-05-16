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

struct Node* deleteDuplicatesUtil
        ( struct Node* head, int value ){
     
    if ( !head )
        return head;
        
    head->next =
        deleteDuplicatesUtil( head->next, head->data );
        
    if ( head->data == value ){
        struct Node* temp = head->next;
        free(head);
        return temp;
    }
    else{
        return head;
    }
            
}

void deleteDuplicates( struct Node* head ){
    
    if ( !head )
        return;
        
    head->next = 
        deleteDuplicatesUtil( head->next, head->data );
    
}

int main(){
    
    struct Node* head = NULL;
    
    head = addNode(head, 23);
    head = addNode(head, 23);
    head = addNode(head, 17);
    head = addNode(head, 11);
    head = addNode(head, 11);
    head = addNode(head, 11);
    head = addNode(head, 4);
    
    printLList(head);
    deleteDuplicates(head);
    printLList(head);

}
