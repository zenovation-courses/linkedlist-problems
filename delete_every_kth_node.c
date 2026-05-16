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

struct Node* 
    deleteEverykthNode( struct Node* head, int k ){

    if ( k <= 0 )
        return head;
    
    struct Node* current = head;
    int nodePosition = 0;
    
    while( current ){
        
        ++nodePosition;
        
        if ( nodePosition % k == (k - 1) ){
            if ( current->next ){
                struct Node* temp =
                    current->next->next;
                free(current->next);
                current->next = temp;
                ++nodePosition;
            }
        }
        struct Node* temp = current;
        current = current->next;
        if ( k == 1 )
            free(temp);
    }
    
    if ( k == 1 )
        return NULL;
    else
        return head;
}

int main(){
    
    struct Node* head = NULL;
    
    head = addNode(head, 12);
    head = addNode(head, 7);
    head = addNode(head, 2);
    head = addNode(head, 8);
    head = addNode(head, 11);
    head = addNode(head, 22);
    head = addNode(head, 45);
    
    printLList(head);
    head = deleteEverykthNode(head, 3);
    printLList(head);

}
