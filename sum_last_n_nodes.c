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

int addLastNNodes(struct Node* head, int n){
    
    struct Node* behind = head, *forward = head;
    int sum = 0;
    
    while( forward && n-- ){
        sum += forward->data;
        forward = forward->next;
    }
    
    if ( forward == NULL )
        return -1;
    
    while ( forward ){
        sum += forward->data;
        sum -= behind->data;
        forward = forward->next;
        behind = behind->next;
    }
    
    return sum;
}


int main(){
    
    struct Node* head = NULL;
    
    head = addNode(head, 12);
    head = addNode(head, 7);
    head = addNode(head, 2);
    head = addNode(head, 8);
    head = addNode(head, 11);
    
    printLList(head);
    int sum = addLastNNodes(head, 3);
    printf("Sum of last n nodes: %d", sum);

}
