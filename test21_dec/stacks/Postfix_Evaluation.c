#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node* next;
} node;

node* top = NULL;

void push(int ch){
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


int main() {
    int t;
    scanf("%d" , &t);
    
    while(t--){
        top = NULL;
        char s[100];
    scanf("%s" , s);   
    while(strcmp(s , "?")){
        
        
        if(strcmp(s , "+") == 0){
            int s2 = top -> data;
            pop();
            int s1 = top -> data;
            pop();
            push(s1 + s2);
        }else if(strcmp(s , "-") == 0){
            int s2 = top -> data;
            pop();
            int s1 = top -> data;
            pop();
            push(s1 - s2);
        }else if(strcmp(s , "*") == 0){
            int s2 = top -> data;
            pop();
            int s1 = top -> data;
            pop();
            push(s1 * s2);
        }else if(strcmp(s , "/") == 0){
            int s2 = top -> data;
            pop();
            int s1 = top -> data;
            pop();
            push(s1 / s2);
        }else{
            push(atoi(s));
        }
        
    scanf("%s" , s);
    }
    
   printf("%d \n" , top -> data);
    }
}
