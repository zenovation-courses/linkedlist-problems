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

struct Node* insertAtPos(struct Node* head, 
                                int num, int pos){

    if ( pos < 1 )
        return head;
        
    if ( pos == 1 ){
        struct Node* temp = makeNode(num);
        temp->next = head;
        return temp;
    }
    
    pos = pos - 2;
    struct Node* current = head;
    
    while(pos && current){
        --pos;
        current = current->next;
    }
    
    if( !current )
        return head;
    
    struct Node* temp = makeNode(num);
    temp->next = current->next;
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
    head = insertAtPos(head, 22, 5);
    printLList(head);

}
