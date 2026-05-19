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

struct Node* reverseEveryGroupOfKNodes
            ( struct Node* head, int k ){

    if( head == NULL || k <= 1 )
        return head;
        
    struct Node* curr = head;
    struct Node* newHead = NULL;
    struct Node* tail = NULL;
        
    while( curr ){
        
        struct Node* groupHead = curr;
        struct Node* prev = NULL;
        struct Node* nextNode = NULL;
        int count = k;
        
        // reverse k nodes iteratively
        while( curr && count-- ){
            nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        
        if ( newHead == NULL )
            newHead = prev;
        
        if ( tail )
            tail->next = prev;
        
        tail = groupHead;
        
    }
    return newHead;
}

int main(){
    
    struct Node* head = NULL;
    
    head = addNode(head, 44);
    head = addNode(head, 2);
    head = addNode(head, 17);
    head = addNode(head, 8);
    head = addNode(head, 14);
    head = addNode(head, 4);
    head = addNode(head, 75);
    
    printLList(head);
    head = reverseEveryGroupOfKNodes(head, 3);
    printLList(head);

}
