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

struct Node* deleteAtPos(struct Node* head, int pos){
    
    if ( pos < 1 || !head )
        return head;
        
    if ( pos == 1 ){
        struct Node* temp = head->next;
        free(head);
        return temp;
    }
    
    pos = pos - 2;
    struct Node* current = head;
    
    while(pos && current){
        --pos;
        current = current->next;
    }
    
    if ( current == NULL || current->next == NULL )
        return head;
        
    struct Node* temp = current->next->next;
    free(current->next);
    current->next = temp;
    
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
    head = deleteAtPos(head, 3);
    printLList(head);

}
