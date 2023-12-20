#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct node{
    int val;
    struct node* next;
} node;

typedef struct queue{
    node* head;
} queue;


typedef struct {
    queue* q1;
    queue* q2;
} MyStack;

void push(queue* q1 , int num){

    if(q1 -> head == NULL){
        q1 -> head = (node*)malloc(sizeof(node));
        q1 -> head -> val = num;
        q1 -> head -> next = NULL;
        return ;
    }

    node* ptr = q1 -> head;
    while(ptr -> next){
        ptr = ptr -> next;
    }

    node* nn = (node*)malloc(sizeof(node));
    nn -> val = num;
    nn -> next = NULL;
    ptr -> next = nn;
}

int pop(queue* q1){
    if(!q1 -> head) return -1;
    node* ptr = q1 -> head;
    int ans = ptr -> val;
    q1 -> head = q1 -> head -> next;
    //free(ptr);
    return ans;
}

int top(queue* q1){
    if(!q1 -> head) return -1;
    return q1 -> head->val;
}

MyStack* st;

void init(queue* q){
    q -> head = NULL;
}

MyStack* myStackCreate() {
    st = (MyStack*)malloc(sizeof(MyStack));
    st -> q1 = (queue*)malloc(sizeof(queue));
    st -> q2 = (queue*)malloc(sizeof(queue));
    init(st -> q1);
    init(st -> q2);
    return st;
}

void myStackPush(MyStack* obj, int x) {
    node* ptr = obj -> q1 -> head;
    while(ptr){
        push(obj -> q2 , ptr -> val);
        pop(obj -> q1);
        ptr = ptr -> next;
    }

    push(obj -> q1 , x);
    ptr = obj -> q2 -> head;

    while(ptr){
        push(obj -> q1 , ptr -> val);
        pop(obj -> q2);
        ptr = ptr -> next;
    }
}

int myStackPop(MyStack* obj) {
    return pop(obj -> q1);
}

int myStackTop(MyStack* obj) {
    return top(obj -> q1);
}

bool myStackEmpty(MyStack* obj) {
    return obj -> q1->head == NULL;
}

void myStackFree(MyStack* obj) {
    free(obj);
}

/**
 * Your MyStack struct will be instantiated and called as such:
 * MyStack* obj = myStackCreate();
 * myStackPush(obj, x);
 
 * int param_2 = myStackPop(obj);
 
 * int param_3 = myStackTop(obj);
 
 * bool param_4 = myStackEmpty(obj);
 
 * myStackFree(obj);
*/