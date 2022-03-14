#include<stdio.h>
#include<stdlib.h>
#define MAX 3
int q[MAX];
int front=-1,rear=-1;
void enqueue(int ele);
void dequeue();
void display();

void enqueue(){
	if(front=-1){
		printf("Queue full\n");
		exit(0);
	}
	rear=(rear+1)%MAX;
	q[rear]=ele;
	if
}

void main(){
	printf("++++++++++++");
}
