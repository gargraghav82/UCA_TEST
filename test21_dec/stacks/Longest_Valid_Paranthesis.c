#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct node{
    int val;
    struct node* next;
} node;

node* top = NULL;

void push(int x){
    node* newTop = (node*)malloc(sizeof(node));
    newTop -> val = x;
    newTop -> next = top;
    top = newTop;
}

void pop(){
    if(!top) return ;
    node* prevTop = top;
    top = top -> next;
    free(prevTop);
}

int longestValidParentheses(char* s) {
    top = NULL;
    push(-1);
    int ans = 0;

    for(int i = 0 ; s[i] != '\0' ; i++){
        if(s[i] == '('){
            push(i);
        }else{
            if(top){
                pop();
            }

            if(top){
                ans = (i - top -> val) > ans ? i - top -> val : ans;
            }else{
                push(i);
            }
        }
    }

    return ans;
}