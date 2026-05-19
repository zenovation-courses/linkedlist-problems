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

struct Node* reverseLL(struct Node* head, int k){
    
    struct Node* prev = NULL;
    
    while( head && k-- ){
        struct Node* temp = head->next;
        head->next = prev;
        prev = head;
        head = temp;
    }
    return prev;
}

struct Node* reverseEveryKNodes
        ( struct Node* head, int k ){

    if ( head == NULL || k <= 1 )
        return head;
    
    struct Node* temp = head;
    int count = k;
    
    while( temp && count-- )
        temp = temp->next;
    
    struct Node* groupHead = reverseLL(head, k);
    
    head->next = reverseEveryKNodes( temp, k );
    
    return groupHead;
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
    head = reverseEveryKNodes(head, 3);
    printLList(head);
}
