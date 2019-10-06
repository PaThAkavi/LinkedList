#include<stdio.h>
#include<stdlib.h>
void insertBeg();
void display();
void insertEnd();
void insertAfter();
void insertBefore();

struct node{
    struct node *prev;
    int data;
    struct node *next;
};

struct node *root = NULL;

int main(){
    while(1){
        int opt;
        printf("1. insert at beginning\n");
        printf("2. Insert in the end\n");
        printf("3. Insert after a particular node\n");
        printf("4. Insert before a particular node\n");
        printf("5. display\n");
        printf("6. Quit\n");

        printf("Please enter your choice : \n");
        scanf("%d", &opt);

        switch(opt){
            case 1: insertBeg(); break;
            case 2: insertEnd(); break;
            case 3: insertAfter(); break;
            case 4: insertBefore(); break;
            case 5: display(); break;
            case 6: exit(0);
            default: printf("Invalid input\n"); 
        }
    }
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

void insertAfter(){
    int ele;
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->prev = NULL;
    newnode->next = NULL;
    printf("Enter the element to be inserted\n");
    scanf("%d", &newnode->data);
    if(root == NULL){
        root = newnode;
    }
    else{
        printf("Enter the element after which insertion should take place\n");
        scanf("%d", &ele);
        struct node *ptr;
        ptr = root;
        while(ptr->data != ele){
            ptr = ptr->next;
        }
        newnode->next = ptr->next;
        newnode->prev = ptr;
        ptr->next->prev = newnode;
        ptr->next = newnode;
    }
}

void insertBefore(){
    int ele;
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->prev = NULL;
    newnode->next = NULL;
    printf("Enter data to be inserted\n");
    scanf("%d", &newnode->data);
    if(root == NULL){
        root = newnode;
    }
    else{
        printf("Enter the element before which insertion is to be taken place : \n");
        scanf("%d", &ele);
        struct node *ptr;
        ptr = root;
        while(ptr->next->data != ele){
            ptr = ptr->next;
        }
        newnode->next = ptr->next;
        newnode->prev = ptr;
        ptr->next = newnode;
        ptr->next->prev = newnode;
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