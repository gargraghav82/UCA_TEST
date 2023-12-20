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


typedef struct node{
    int val;
    struct node* next;
} node;



typedef struct {
    node* head;
    node* tail;
    int size;
    int cap;
} MyCircularQueue;

MyCircularQueue* q;

MyCircularQueue* myCircularQueueCreate(int k) {
    q = (MyCircularQueue*)malloc(sizeof(MyCircularQueue));
    q -> head = NULL;
    q -> tail = NULL;
    q -> size = 0;
    q -> cap = k;
    return q;
}

bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {

    if(obj -> size == obj -> cap) return false;

    if(obj -> head == NULL && obj -> tail == NULL){
        obj -> head = (node*)malloc(sizeof(node));
        obj -> tail = (node*)malloc(sizeof(node));
        obj -> head -> val = value;
        obj -> head -> next = NULL;
        obj -> tail = obj -> head;
        obj -> tail -> next = obj -> head;
    }else{
        node* newTail = (node*)malloc(sizeof(node));
        newTail -> val = value;
        obj -> tail -> next = newTail;
        newTail -> next = obj -> head;
        obj -> tail = newTail;
    }

    obj -> size++;
    return true;
}

bool myCircularQueueDeQueue(MyCircularQueue* obj) {
    if(obj -> head == NULL) return false;
    else if(obj -> size == 1){
        //free(obj -> head);
        obj -> head = NULL;
        obj -> tail = NULL;
    }else{
        node* ptr = obj -> head;
        //printf("%d" , obj -> head -> val);
        obj -> head = obj -> head -> next;
        obj -> tail -> next = obj -> head;
        //free(ptr);
    }
    obj -> size--;
    return true;
}

int myCircularQueueFront(MyCircularQueue* obj) {
    if(obj -> head == NULL) return -1;
    return obj -> head -> val;
}

int myCircularQueueRear(MyCircularQueue* obj) {
    if(obj -> tail == NULL) return -1;
    return obj -> tail -> val;
}

bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
    return obj -> head == NULL;
}

bool myCircularQueueIsFull(MyCircularQueue* obj) {
    return obj -> size == obj -> cap;
}

void myCircularQueueFree(MyCircularQueue* obj) {
    free(obj);
}