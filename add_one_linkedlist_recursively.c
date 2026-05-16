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

int addOneRecursively(struct Node* head){
    
    if ( head->next == NULL ){
        int res = head->data + 1;
        head->data = res % 10;
        return res / 10;        // return carry
    }
    
    int res = 
        head->data + addOneRecursively(head->next);
    
    head->data = res % 10;
    return res / 10;     // return carry
    
}

struct Node* addOneToLL(struct Node* head){
    
    if( !head )
        return head;
    
    int carry = addOneRecursively(head);
    
    if ( carry ){
        struct Node* newNode =
            (struct Node*)malloc(sizeof(struct Node*));
        newNode->data = carry;
        newNode->next = head;
        return newNode;
    }
    
    return head;
    
}

int main(){
    
    struct Node* head = NULL;
    
    head = addNode(head, 9);
    head = addNode(head, 9);
    head = addNode(head, 9);
    head = addNode(head, 1);
    
    printLList(head);
    head= addOneToLL(head);
    printLList(head);

}
