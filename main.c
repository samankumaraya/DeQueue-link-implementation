#include<stdio.h>
#include<stdlib.h>

#define MAXDEQUEUE 20

typedef struct node{
 int data;
 struct node *next,*prev;
}Node;

typedef struct{
 int count;
 int full;
 Node *front;
 Node *rear;
}DeQueue;

void CreatDeQueue(DeQueue *dq){
 dq->count=0;
 dq->full=0;
 dq->front=dq->rear=NULL;
}

int IsDeQueueEmpty(DeQueue *dq){
 return(dq->front==NULL);
}

int IsDeQueueFull(DeQueue *dq){
 return(dq->full);
}

void insertrear(DeQueue *dq,int x){
 Node *newnode;
 newnode=(Node *)malloc(sizeof(Node));

 if(newnode==NULL){
    dq->full=1;
    printf("Overflow \n");
    exit(1);
 }
 else{
    if(dq->rear==NULL){
        dq->rear=dq->front=newnode;
    }else{
       newnode->prev=dq->rear;
       dq->rear->next=newnode;
       dq->rear=newnode;
    }
    dq->rear->data=x;
    dq->count++;
 }
}

void insertfront(DeQueue*dq, int x){
 Node *newnode;
 newnode=(Node *)malloc(sizeof(Node));

 if(newnode==NULL){
    dq->full=1;
    printf("Overflow \n");
    exit(1);
 }else{
    if(dq->front=NULL){
        dq->front=dq->rear==newnode;
    }
    else{
       newnode->data=x;
       dq->front->prev=newnode;
       dq->front=newnode;
    }
    dq->front->data=x;
    dq->count++;
 }
}

void deletarear(DeQueue *dq,int *x){
 if(IsDeQueueEmpty(dq)){
    printf("Dequeue is empty...");
    exit(1);
 }
 else{
    *x=dq->rear->data;
    Node *temp=(Node *)malloc(sizeof(Node));
    temp=dq->rear;
    dq->rear=dq->rear->prev;
      if(dq->rear=NULL){
        dq->front=NULL;
      }
      else{
        dq->rear->next=NULL;
        free(temp);
      }

 }

}

void deletefront(DeQueue *dq,int x){
   if(IsDeQueueEmpty(dq)){
    printf("Dequeue is empty...");
    exit(1);
 }
 else{
    *x=dq->front->data;
    Node *temp=(Node *)malloc(sizeof(Node));

    temp=dq->front;
    dq->front=dq->front->next;
     if(dq->front=NULL){
        dq->rear=NULL;
     }else{
      dq->front->prev=NULL;
     }
}




