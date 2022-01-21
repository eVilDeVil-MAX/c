#include<stdio.h>
#include<stdlib.h>

struct Node{
    struct Node *next;
    int data;
};  

void traverse(struct Node *ptr){
    while(ptr!=NULL){
        printf("element %d\n",ptr->data);
        ptr = ptr->next;
    }
}

struct Node *memoryallocation(void){
    return  malloc(sizeof(struct Node));

}
struct Node *insertatfirstp(struct Node *head , int data){
    struct Node *ptr;
    ptr = memoryallocation();
    ptr->data = data;
    ptr->next = head;
    return ptr;
}


struct Node *insertatlastp(struct Node *currentlast , int data){
    struct Node *ptr;
    ptr = memoryallocation();
    ptr->next = currentlast;
    while(ptr->next!=NULL){
        ptr = ptr->next;
    }
    ptr->next = NULL;   
    ptr -> data = data;
    return ptr;

}


struct Node *insertinbetween(struct Node *head , int data , int index){
        struct Node *ptr = malloc(sizeof(struct Node));
        struct Node *p=head; 
        int i  = 0;
        while (i!=index-1){
            p = p->next;
            i++;
        }
        ptr->next = p->next;
        p->next = ptr;
        ptr->data = data;
        return head;
}

struct Node *deletefirst(struct Node *head ){
    struct Node *ptr = head;
    head = head->next;
    free(ptr);
    return head;
}

struct Node *delatind(struct Node *head , int index){
    struct Node  *ptr = head;
    struct Node *p = head->next;
    int i = 0;
    while (i!=index )
    {
        ptr = ptr ->next;
        p = p->next;
        i++;
    }
    ptr->next = p -> next;
    free(p);
    return head; 
}

struct Node *delatend(struct Node *head){
    struct Node *ptr = head;
    struct Node *p = head->next;
    while(p->next!=NULL){
        p = p->next;
        ptr = ptr->next;
    }
    ptr->next = NULL;
    free(p);
    return head;
}

int main(void){
    struct Node *head;
    struct Node *first;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;
    struct Node *fifth;
    struct Node *sixth;
    struct Node *seventh;

    head = memoryallocation();
    first = memoryallocation();
    second = memoryallocation();
    third = memoryallocation();
    fourth = memoryallocation();
    fifth = memoryallocation();
    sixth = memoryallocation();
    seventh = memoryallocation();

    head->data=21;
    head->next=first;

    first->data=23;
    first->next=second;

    second->data=52;
    second->next=third;

    third->data=344;
    third->next=fourth;

    fourth->data=123;
    fourth->next=fifth;

    fifth->data=220;
    fifth->next=sixth;

    sixth->data=822;
    sixth->next=seventh;

    seventh->data=98;
    seventh->next=NULL;

    printf("list before insertion\n");
    traverse(head);
    printf("list after insertion at first position \n");
    head = insertatfirstp(head,100);
    traverse(head);
    printf("list after insertion at last position \n");
    seventh = insertatlastp(head , 10001);
    traverse(head);
    printf("list after inserting a element in between\n");
    head = insertinbetween(head , 333 , 5);
    traverse(head);
    printf("list after deleting first element\n");
    head =  deletefirst(head);
    traverse(head);
    printf( " list after deleteion at index\n");
    head = delatind(head,3);
    traverse(head);
    printf("list after deletion  at the end");
    head = delatend(head);
    traverse(head);    
    return 0; 

}
