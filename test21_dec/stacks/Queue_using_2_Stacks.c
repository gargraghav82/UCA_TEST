#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct node{
    int val;
    struct node* next;
} node;

typedef struct stack{
    struct node* top;
} stack;

void init(stack *st){
    st -> top = NULL;
}

void push(stack* st , int num){
    node* newTop = (node*)malloc(sizeof(node));
    newTop -> val = num;
    newTop -> next = st -> top;
    st -> top = newTop;
}

int pop(stack* st){
    if(st -> top == NULL) return -1;
    node* ptr = st -> top;
    st -> top = st -> top -> next;
    int ans = ptr -> val;
    free(ptr);
    return ans;
}

int peek(stack* st){
    if(st -> top == NULL) return -1;
    return st -> top -> val;
}

bool isEmpty(stack* st){
    return st -> top == NULL;
}

typedef struct {
    stack* s1; 
    stack* s2;
} MyQueue;

MyQueue* q;


MyQueue* myQueueCreate() {
    q = (MyQueue*)malloc(sizeof(MyQueue));
    q -> s1 = (stack*)(malloc(sizeof(stack)));
    q -> s2 = (stack*)(malloc(sizeof(stack)));
    init(q -> s1);
    init(q -> s2);
    return q;
}

void myQueuePush(MyQueue* obj, int x) {
    while(obj -> s1 -> top){
        push(obj -> s2 , obj -> s1 -> top -> val);
        pop(obj -> s1);
    }

    push(obj -> s1 , x);

    while(obj -> s2 -> top){
        push(obj -> s1 , obj -> s2 -> top -> val);
        pop(obj -> s2);
    }
}

int myQueuePop(MyQueue* obj) {
    return pop(obj -> s1);
}

int myQueuePeek(MyQueue* obj) {
    return peek(obj -> s1);
}

bool myQueueEmpty(MyQueue* obj) {
    return isEmpty(obj -> s1);
}

void myQueueFree(MyQueue* obj) {
    
}

/**
 * Your MyQueue struct will be instantiated and called as such:
 * MyQueue* obj = myQueueCreate();
 * myQueuePush(obj, x);
 
 * int param_2 = myQueuePop(obj);
 
 * int param_3 = myQueuePeek(obj);
 
 * bool param_4 = myQueueEmpty(obj);
 
 * myQueueFree(obj);
*/