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

void deleteDuplicates(struct Node* head){
    
    while ( head && head->next ){
        
        if ( head->data == head->next->data ){
            struct Node* temp = head->next->next;
            free(head->next);
            head->next = temp;
        }
        else{
            head = head->next;           
        }
    }
    
}

int main(){
    
    struct Node* head = NULL;
    
    head = addNode(head, 23);
    head = addNode(head, 23);
    head = addNode(head, 17);
    head = addNode(head, 11);
    head = addNode(head, 11);
    head = addNode(head, 11);
    head = addNode(head, 8);
    
    printLList(head);
    deleteDuplicates(head);
    printLList(head);

}
