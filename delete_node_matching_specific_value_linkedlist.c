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

struct Node* deleteNode(struct Node* head, int num){
    
    if ( !head )
        return NULL;
    
    struct Node* prev = NULL, *temp = head;
    
    if ( head->data == num ){
        temp = head->next;
        free(head);
        return temp;
    }
    
    while( temp &&  temp->data != num ){
        prev = temp;
        temp = temp->next;
    }
    
    if ( !temp )
        return head;
        
    prev->next = temp->next;
    free(temp);
    
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
    head = deleteNode(head, 47);
    printLList(head);


}
