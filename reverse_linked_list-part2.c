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

struct Node* reverseLL(struct Node* head){
    
    if ( head == NULL || head->next == NULL )
        return head;
    
    struct Node* ret = reverseLL(head->next);
    
    head->next->next = head;
    head->next = NULL;
    
    return ret;
}

int main(){
    
    struct Node* head = NULL;
    
    addNode(&head, 23);
    addNode(&head, 43);
    addNode(&head, 7);
    addNode(&head, 2);
    addNode(&head, 11);
    
    printLList(head);
    
    head = reverseLL(head);
    
    printLList(head);
    
    

}
