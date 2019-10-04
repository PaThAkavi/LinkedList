#include<stdio.h>
#include<stdlib.h>
void addAtEnd();
void addAtBeg();
void display();
int length();
void deleteBeg();
void deleteEnd();
void deleteParticular(int);

struct node{
    int data;
    struct node *link;
};

struct node *root = NULL;

int main(){
    while(1){
        printf("Single linked list operations : \n");
        int option;
        printf("1. Add element at the end \n");
        printf("2. Add element in the beginning \n");
        printf("3. display all the elements \n");
        printf("4. Find the length of the list \n");
        printf("5. Delete node from begenning \n");
        printf("6. Delete node from end \n");
        printf("7. Exit\n");
        scanf("%d", &option);

        switch(option){
            case 1: addAtEnd(); printf("--------------------------------------\n"); break;
            case 2: addAtBeg(); printf("--------------------------------------\n"); break;
            case 3: display(); printf("--------------------------------------\n"); break;
            case 4: printf("The number of elements in the list : %d\n",length()); printf("--------------------------------------\n"); break;
            case 5: deleteBeg(); break;
            case 6: deleteEnd(); break;
            case 7: exit(0);
            default: printf("Invalid input"); printf("--------------------------------------\n");
        }
    }
    return 0;
}

void addAtEnd(){
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->link = NULL;
    printf("Please enter the data value : \n");
    scanf("%d", &newnode->data);
    if(root == NULL){
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

void addAtBeg(){
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->link = NULL;
    printf("Enter the node data value : \n");
    scanf("%d", &newnode->data);
    if(root == NULL){
        root = newnode;
    }
    else{
        struct node *ptr;
        ptr = root;
        newnode->link = root;
        root = newnode;
    }
}

int length(){
    int count;
    if(root == NULL){
        return 0;
    }
    else{
        struct node *ptr;
        ptr = root;
        while(ptr != NULL){
            ptr = ptr->link;
            count++;
        }
        return count;
    }
}

void display(){
    printf("The elements in the list are : \n");
    if(root == NULL){
        printf("No elements present.\n");
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

void deleteBeg(){
    struct node *ptr;
    ptr = root;
    root = ptr->link;
}

void deleteEnd(){
    struct node *ptr;
    ptr = root;
    while(ptr->link->link != NULL){
        ptr = ptr->link;
    }
    ptr->link = NULL;
}

void deleteParticular(int ele){

}