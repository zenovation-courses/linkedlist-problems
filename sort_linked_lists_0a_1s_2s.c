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

void addNode(struct Node** newHead, int num){
    
    struct Node* temp = 
        (struct Node*)malloc(sizeof(struct Node));
    temp->data = num;
    temp->next = *newHead;
    *newHead = temp;
}

void sortLL(struct Node* head){
    
    if ( !head )
        return;
     
    struct Node* tempHead = head;   
    int freq[3] = {0, 0, 0};
    
    while( head ){
        ++(freq[head->data]);
        head = head->next;
    }
    
    int index = 0;
    
    while( tempHead ){
        
        if ( freq[index] == 0 ){
            index++;
        }
        
        tempHead->data = index;
        --(freq[index]);
        tempHead = tempHead->next;
    }    
}

int main(){
    
    struct Node* head = NULL;
    
    addNode(&head, 0);
    addNode(&head, 2);
    addNode(&head, 1);
    addNode(&head, 0);
    addNode(&head, 2);
    addNode(&head, 0);
    addNode(&head, 1);
    addNode(&head, 1);

    printLList(head);
    sortLL(head);
    printLList(head);

}
