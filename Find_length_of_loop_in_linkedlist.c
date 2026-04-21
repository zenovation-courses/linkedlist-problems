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

int countNodesInLoop(struct Node* head){
 
    int count = 0;
    struct Node* fast = head, *slow = head;
    
    while(fast && fast->next){
        fast = fast->next->next;
        slow = slow->next;
        
        if (slow == fast){
            do{
                ++count;
                fast = fast->next;
            }while(fast != slow);
            return count;
        }
    }
    
    return count;
}




int main(){
    
    struct Node* head = NULL;
    
    addNode(&head, 23);
    struct Node* temp = head;
    addNode(&head, 43);
    addNode(&head, 7);
    temp->next = head;
    
    addNode(&head, 2);
    addNode(&head, 11);
    
    printf("Length of loop is %d", 
                    countNodesInLoop(head));

}
    
    


