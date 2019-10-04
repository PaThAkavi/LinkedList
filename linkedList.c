#include<stdio.h>
#include<stdlib.h>
void append();
void display();
int length();
void insertbeg();

struct node{
    int data;
    struct node *link;
};

struct node *root = NULL;

int main(){
    append();
    append();
    append();
    display();
    printf("%d\n", length());
    insertbeg();
    insertbeg();
    display();
    printf("%d\n", length());
    return 0;
}

void append(){
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter the node value : \n");
    scanf("%d", &newnode->data);
    newnode->link = NULL;
    if(root==NULL){
        root = newnode;
    }
    else{
        struct node *ptr;
        ptr = root;
        while(ptr->link != NULL){
            ptr = ptr->link;
        }
        ptr->link = newnode;
    }
}

void display(){
    printf("The elements of the linked list are : \n");
    if(root == NULL){
        printf("There are no elements in the list as of now. \n");
    }
    else{
        struct node *ptr;
        ptr = root;
        while(ptr != NULL){
            printf("%d->", ptr->data);
            ptr = ptr->link;
        }
        printf("\n");
    }
}

int length(){
    if(root == NULL){
        return 0;
    }
    else{
        struct node *ptr;
        ptr = root;
        int count = 0;
        while(ptr != NULL){
            count ++ ;
            ptr = ptr->link;
        }
        return count;
    }
}

void insertbeg(){
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter node value to be inserted in the begenning : \n");
    scanf("%d", &newnode->data);
    newnode->link = NULL;
    if(root == NULL){
        root = newnode;
    }
    else{
        newnode->link = root;
        root = newnode;
    }
}