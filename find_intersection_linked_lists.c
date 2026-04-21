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


void getNode(struct Node* longList, struct Node* shortList, 
                                    int diff){

    while(diff){
        longList = longList->next;
        --diff;
    }
    
    while( longList && shortList && longList != shortList ){
        longList = longList->next;
        shortList = shortList->next;
    }
    
    if ( !longList || !shortList ){
        printf("No intersection\n");
        return;
    }
    
    printf("Intersection point: %d\n", longList->data);
    return;
                                        
}

void findIntersection(struct Node* head1, struct Node* head2){
    
    if ( head1 == NULL || head2 == NULL ){
        printf("No intersection\n");
        return;
    } 
    
    int count1 = 1, count2 = 1;
    struct Node* temp1 = head1, *temp2 = head2;
    
    while(temp1->next){
        ++count1;
        temp1 = temp1->next;
    }
    
    printf("Count of nodes in List 1: %d\n", count1);
    
    while(temp2->next){
        ++count2;
        temp2 = temp2->next;
    }
    
    printf("Count of nodes in List 2: %d\n", count2);
    
    if ( count1 > count2 )
        getNode(head1, head2, count1 - count2);
    else
        getNode(head2, head1, count2 - count1);
    
    return;
}




int main(){
    
    struct Node* head1 = NULL, *head2 = NULL;
    
    // First Linked List
    addNode(&head1, 23);
    addNode(&head1, 43);
    addNode(&head1, 7);
    struct Node* temp = head1;
    addNode(&head1, 2);
    addNode(&head1, 11);

    // Second Linked List
    addNode(&head2, 19);
    head2->next = temp;
    addNode(&head2, 52);
    addNode(&head2, 88);
    addNode(&head2, 14);

    printLList(head1);
    printLList(head2);
    
    findIntersection(head1, head2);

}
