#include<stdio.h>
#include<stdlib.h>
void append();

struct node{
    int data;
    struct node *link;
};

struct node *root = NULL;

int main(){
    append();
    return 0;
}

void append(){
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter the node value : \n");
    scanf("%d", &newnode->data);
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