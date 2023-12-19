#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

typedef struct node{
    char data;
    struct node* next;
} node;

node* top = NULL;

void insert(char ch){
    node* newTop = malloc(sizeof(node));
    newTop -> data = ch;
    newTop -> next = top;
    top = newTop;
}

void pop(){
    node* prevTop = top;
    top = top -> next;
    free(prevTop);
}

bool isValid(char* s) {
    top = NULL;
    

    for(int i = 0 ; s[i] != '\0' ; i++){
        if(s[i] == '(' || s[i] == '{' || s[i] == '['){
            insert(s[i]);
        }else{
            if(!top) return false;
            else if(s[i] == ')' && top -> data == '(') pop();
            else if(s[i] == ']' && top -> data == '[') pop();
            else if(s[i] == '}' && top -> data == '{') pop();
            else return false;
        }
    }

    return top == NULL;
}