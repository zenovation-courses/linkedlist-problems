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

struct Node* mergeLList(struct Node* head1, struct Node* head2){
    
    struct Node* mergedListHead = NULL, *mergedList = NULL;
    
    if ( !head1 )
        return head2;
        
    if ( !head2 )
        return head1;
        
    if ( head1->data < head2->data ){
        mergedList = head1;
        head1 = head1->next;
    }
    else{
        mergedList = head2;
        head2 = head2->next;
    }    
    mergedListHead = mergedList;
    
    while( head1 && head2 ){
        if ( head1->data < head2->data ){
            mergedList->next = head1;
            mergedList = head1;
            head1 = head1->next;
        }
        else{
            mergedList->next = head2;
            mergedList = head2;
            head2 = head2->next;
        }
    }
    
    if ( !head1 )
        mergedList->next = head2;
    
    if ( !head2 )
        mergedList->next = head1;
    
    
    return mergedListHead;
}

int main(){
    
    struct Node* head1 = NULL, *head2 = NULL, *head3 = NULL;
    
    // First Linked List
    addNode(&head1, 137);
    addNode(&head1, 121);
    addNode(&head1, 100);
    addNode(&head1, 55);
    addNode(&head1, 16);
    addNode(&head1, 14);
    addNode(&head1, 9);
    addNode(&head1, 3);

    // Second List
    addNode(&head2, 245);
    addNode(&head2, 61);
    addNode(&head2, 49);
    addNode(&head2, 7);
    addNode(&head2, 5);

    printLList(head1);
    printLList(head2);

    head3 = mergeLList(head1, head2);
    
    printLList(head3);
}
