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


struct Node* reverseLL( struct Node* prev, 
                            struct Node* head){

    struct Node* temp = NULL;
    
    if ( !head )
        return NULL;
        
    while( head ){
        temp = head->next;
        head->next = prev;
        prev = head;
        head = temp;
    }

    return prev;                           
}

void checkNodes( struct Node* first, struct Node* second ){
    
    while( first && second ){
        if( first->data  !=  second->data ){
            printf("Not a palindrome\n");
            return;
        }
        
        first = first->next;
        second = second->next;
    }
    
    printf("Linked List is a palindrome\n");
    return;
    
}

void isPalindrome(struct Node* head){
    
    if ( !head ){
        printf("Linked List is empty");
        return;
    }
    
    struct Node* fast = head, *slow = head,
                            *reversedHead = NULL;
    
    while( fast && fast->next ){
        fast = fast->next->next;
        
        if ( fast )
            slow = slow->next;
        else
            break;
        
    }
    
    reversedHead = reverseLL( NULL, slow->next );
    slow->next = NULL;
    
    checkNodes(head, reversedHead);
    
}



int main(){
    
    struct Node* head = NULL;
    
    addNode(&head, 12);
    addNode(&head, 7);
    addNode(&head, 47);
    addNode(&head, 7);
    addNode(&head, 12);

    printLList(head);
    isPalindrome(head);

}
