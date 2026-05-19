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

struct Node* seggregateEvenOddNodes(struct Node* head){
    
    struct Node* resultHead = NULL;
    struct Node* resultLast = NULL;
    
    struct Node* curr = head;
    struct Node* prev = NULL;
    
    while( curr ){
        
        if ( curr->data % 2 == 0 ){
            
            if ( prev )
                prev->next = curr->next;
            else
                // head points to first odd node
                head = curr->next; 
            
            if ( resultHead == NULL ){
                resultHead = curr;
                resultLast = curr;
            }else{
                resultLast->next = curr;
                resultLast = resultLast->next;
            }
            curr = curr->next;
        }
        else{
            prev = curr;
            curr = curr->next;
        }
        
    }
    
    if ( resultLast ){
        resultLast->next = head;
        return resultHead;
    }else{
        return head;
    }  
}

int main(){
    
    struct Node* head = NULL;
    
    head = addNode(head, 2);
    head = addNode(head, 23);
    head = addNode(head, 17);
    head = addNode(head, 8);
    head = addNode(head, 0);
    
    printLList(head);
    head = seggregateEvenOddNodes(head);
    printLList(head);

}
