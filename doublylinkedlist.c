#include<stdio.h>
#include<stdlib.h>

struct Node
{
    struct Node *prev;
    struct Node *next;
    int data;
    
};

void traversal(struct Node *head){
    struct Node *ptr = head;
    while(ptr->next!=NULL){
        printf("element: %d\n",ptr->data);
        ptr = ptr->next;
    }
}



int main(void){
    struct Node *head = (struct Node *) malloc(sizeof(struct Node));
    struct Node *first = (struct Node *)malloc(sizeof(struct Node));
    struct Node *second = (struct Node *)malloc(sizeof(struct Node));
    struct Node *third = (struct Node *)malloc(sizeof(struct Node));
    struct Node *fourth = (struct Node *)malloc(sizeof(struct Node));
    struct Node *fifth = (struct Node *)malloc(sizeof(struct Node));
    struct Node *sixth = (struct Node *)malloc(sizeof(struct Node));

    head->data = 21;
    head->prev = NULL;
    head->next = second;

    second->data = 83;
    second->prev = head;
    second->next = third; 

    third->data = 248;
    third->prev = second;
    third->next = fourth;

    fourth->data = 4352;
    fourth->prev = third;
    fourth->next = fifth;

    fifth->data = 892;
    fifth->prev = fourth;
    fifth->next = sixth;

    sixth->data = 1;
    sixth->prev = fifth;
    sixth->next = NULL;

    traversal(head);
    return 0;
} 

