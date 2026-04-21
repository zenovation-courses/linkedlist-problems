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

void findMiddle(struct Node* head){
    
    struct Node* slow = head, *fast = head;
    
    while(fast && fast->next){
        fast = fast->next->next;
        slow = slow->next;
    }
    
    if (slow)
        printf("Middle element: %d", slow->data);
    else
        printf("List empty");
    
}

int main(){
    
    struct Node* head = NULL;
    
    addNode(&head, 23);
    addNode(&head, 43);
    addNode(&head, 7);
    addNode(&head, 2);
    addNode(&head, 11);
    
    findMiddle(head);

}
