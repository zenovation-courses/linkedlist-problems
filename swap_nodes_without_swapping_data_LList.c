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

struct Node* swapNodes(struct Node* head, int X, int Y){
    
    if( X == Y )
        return head;
        
    struct Node* prevX = NULL, *currX = NULL;
    struct Node* prevY = NULL, *currY = NULL;
    struct Node* prev = NULL, *curr = head;
    
    while( curr ){
        if( curr->data == X ){
            prevX = prev;
            currX = curr;
        }
        else if ( curr->data == Y ){
            prevY = prev;
            currY = curr;
        }
        prev = curr;
        curr = curr->next;
    }
    
    if ( currX == NULL || currY == NULL )
        return head;
    
    if ( prevX )
        prevX->next = currY;
    else
        head = currY;
    
    if ( prevY )
        prevY->next = currX;
    else
        head = currX;
    
    struct Node* temp = currY->next;
    currY->next = currX->next;
    currX->next = temp;
    
    return head;
}

int main(){
    
    struct Node* head = NULL;
    
    head = addNode(head, 79);
    head = addNode(head, 23);
    head = addNode(head, 17);
    head = addNode(head, 11);
    head = addNode(head, 9);
    head = addNode(head, 11);
    head = addNode(head, 4);
    
    printLList(head);
    head = swapNodes(head, 4, 79);
    printLList(head);

}
