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

void getNthNode(struct Node* head, int index){
    
    int count = 1;
    
    while(head){
        if( count == index ){
            printf("N is %d\n", index);
            printf("Nth node is %d\n", head->data);
            return;
        }
        
        head = head->next;
        ++count;
    }
    
    printf("Couldn't find Nth node as linked list is short");
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
    getNthNode(head, 23);

}
