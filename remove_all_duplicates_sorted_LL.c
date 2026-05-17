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

void deleteLL(struct Node* head){
    
    while ( head ){
        struct Node* temp = head->next;
        free(head);
        head = temp;
    }
    
}

struct Node* removeAllDuplicates(struct Node* head){
    
    if ( head == NULL || head->next == NULL )
        return head;
        
    struct Node* dummy = 
        (struct Node*)malloc(sizeof(struct Node));
    dummy->next = head;
    
    struct Node* prev = dummy, *current = head;
    
    while ( current ){
        
        if ( current->next && prev->next->data == current->next->data )
            current = current->next;
        else if ( prev->next != current ){
            struct Node* temp = current;
            current = current->next;
            temp->next = NULL;
            deleteLL(prev->next);
            prev->next = current;
        }
        else{
            prev = current;
            current = current->next;
        }
    }
    return dummy->next;
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
    head = removeAllDuplicates(head);
    printLList(head);

}
