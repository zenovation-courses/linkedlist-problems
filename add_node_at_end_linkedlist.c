#include <stdio.h>

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

struct Node* makeNode(int num){
    struct Node* newNode =
            (struct Node* )malloc(sizeof(struct Node));
    newNode->data = num;
    newNode->next = NULL;
    return newNode;
}

struct Node* insertATEnd(struct Node* head, int num){
    
    struct Node* temp = head;
    
    if( !head ){
        head = makeNode(num);
        return head;
    }
    
    while(temp->next){
        temp = temp->next;
    }
    
    temp->next = makeNode(num);
    
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
    head = insertATEnd(head, 35);
    printLList(head);

}
