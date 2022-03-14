#include<stdio.h>
#include<stdlib.h>
#define MAX 3
int q[MAX];
int front=-1,rear=-1;
void enqueue(int);
int dequeue();
void display();

void enqueue(int ele){
	rear=(rear+1)%MAX;
	if(front==rear){
		printf("Queue full\n");
		exit(0);
	}
	
	q[rear]=ele;
	if(front==-1)
		front=0;
}

int dequeue(){
	int ele;
	if(front==-1){
		printf("Queue Empty!");
		exit(0);
	}
	ele=q[front];
	if(front==rear)
		front=rear=-1;
	else
		front=(front+1)%MAX;
	return ele;
}

void display(){
	int i;
	if(front==-1)
		printf("queue is empty");
	else if(front<=rear)
		for(i=front;i<=rear;i++)
			printf("\t%d",q[i]);
	else{
		for(i=front;i<MAX;i++)
			printf("\t%d",q[i]);
		for(i=0;i<=rear;i++)
			printf("\t%d",q[i]);
	}
}
void main(){
	int ch,ele;
	while(1){
	printf("++++++++++++");
	printf("\n1.INSRT\t2.DLET\n3.DISPLY\t4.EXT");
	printf("\n Enter your choice:\t");
	scanf("%d",&ch);
	switch(ch){
	case 1:
		printf("Enter an element:\t");
		scanf("%d",&ele);
		enqueue(ele);
		break;	
		
	case 2:
		ele=dequeue();
		printf("%d deleted!\n",ele);
		break;		
		
	case 3:
		display();
		break;
	case 4:
		exit(0);
}
}
}
