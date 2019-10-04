// SINGLE LINKED LIST
#include<stdio.h>
#include<stdlib.h>
void addAtEnd();
void addAtBeg();
void display();
int length();
void deleteBeg();
void deleteEnd();
void deleteParticular();
void addAfter();
void addBefore();

struct node{
    int data;
    struct node *link;
};

struct node *root = NULL;

int main(){
    while(1){
        int option;
        printf("Single linked list operations : \n");
        printf("1. Add element at the end \n");
        printf("2. Add element in the beginning \n");
        printf("3. Add element after a specified node \n");
        printf("4. Add element before a specified node \n");
        printf("5. display all the elements \n");
        printf("6. Find the length of the list \n");
        printf("7. Delete node from begenning \n");
        printf("8. Delete node from end \n");
        printf("9. Delete a particular node. \n");
        printf("10. Exit\n");
        printf("\n");
        printf("Enter your choice : \n");
        scanf("%d", &option);

        switch(option){
            case 1: addAtEnd(); 
                    printf("--------------------------------------\n"); 
                    break;
            case 2: addAtBeg(); 
                    printf("--------------------------------------\n"); 
                    break;
            case 3: addAfter(); 
                    break;
            case 4: addBefore(); 
                    break;
            case 5: display(); 
                    printf("--------------------------------------\n"); 
                    break;
            case 6: printf("The number of elements in the list : %d\n",length()); 
                    printf("--------------------------------------\n"); 
                    break;
            case 7: deleteBeg(); 
                    break;
            case 8: deleteEnd(); 
                    break;
            case 9: deleteParticular(); 
                    break;
            case 10: exit(0);
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
    if(root == NULL){
        printf("No elements present.\n");
    }
    else{
        printf("The elements in the list are : \n");
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
    if(root == NULL){
        printf("There are currently no elements in the list to delete. \n");
        printf("----------------------------------------------------------\n");
    }
    else{
        struct node *ptr;
        ptr = root;
        root = ptr->link;
    }
    
}

void deleteEnd(){
    if(root == NULL){
        printf("There are currently no elements in the list to delete. \n");
        printf("----------------------------------------------------------\n");
    }
    else{
        struct node *ptr;
        ptr = root;
        while(ptr->link->link != NULL){
            ptr = ptr->link;
        }
        ptr->link = NULL;
    }
}

void deleteParticular(){
    int ele;
    if(root == NULL){
        printf("There are currently no elements in the list to delete. \n");
        printf("----------------------------------------------------------\n");
    }
    else{
        printf("Enter the element to be deleted : \n");
        scanf("%d", &ele);
        struct node *ptr;
        ptr = root;
        while(ptr->link->data != ele){
            ptr = ptr->link;
        }
        ptr->link = ptr->link->link;
    }
}

void addAfter(){
    int ele;
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter the data value to be inserted : \n");
    scanf("%d", &newnode->data);
    if(root == NULL){
        newnode->link = NULL;
        root = newnode;
    }
    else{
        printf("Enter the element after which insertion will take place : \n");
        scanf("%d", &ele);
        struct node *ptr;
        ptr = root;
        while(ptr->data != ele){
            ptr = ptr->link;
        }
        newnode->link = ptr->link;
        ptr->link = newnode;
    }
}

void addBefore(){
    int ele;
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter the data value to be inserted : \n");
    scanf("%d", &newnode->data);
    if(root == NULL){
        newnode->link = NULL;
        root = newnode;
    }
    else{
        printf("Enter the element before which deletion will take place : \n");
        scanf("%d", &ele);
        struct node *ptr;
        ptr = root;
        while(ptr->link->data != ele){
            ptr = ptr->link;
        }
        newnode->link = ptr->link;
        ptr->link = newnode;
    }
}