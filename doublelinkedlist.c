#include<stdio.h>
#include<stdlib.h>
void insertBeg();
void display();
void insertEnd();

struct node{
    struct node *prev;
    int data;
    struct node *next;
};

struct node *root = NULL;

int main(){
    insertBeg();
    insertBeg();
    insertEnd();
    insertEnd();
    display();
    return 0;
}

void insertBeg(){
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->next = NULL;
    newnode->prev = NULL;
    printf("Enter the value to be inserted\n");
    scanf("%d", &newnode->data);
    if(root == NULL){
        root = newnode;
    }
    else{
        struct node *ptr;
        ptr = root;
        newnode->next = root;
        root = newnode;
    }
}

void insertEnd(){
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->next = NULL;
    newnode->prev = NULL;
    printf("Enter the value to be inserted\n");
    scanf("%d", &newnode->data);
    if(root == NULL){
        root = newnode;
    }
    else{
        struct node *ptr;
        ptr = root;
        while(ptr->next != NULL){
            ptr = ptr->next;
        }
        ptr->next = newnode;
        newnode->prev = ptr;
    }
}

void display(){
    if(root == NULL){
        printf("No elements in the list\n");
    }
    else{
        struct node *ptr;
        ptr = root;
        while(ptr != NULL){
            printf("%d->", ptr->data);
            ptr = ptr->next;
        }
        printf("\n");
    }
}