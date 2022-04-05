#include<stdio.h>
#include<stdlib.h>

#define MAX 4
int q[MAX];
int front=-1;
int rear=-1;
void enqueue(int);
void delete();
void display();

void enqueue(int ele){
	if(rear==MAX-1)
		printf("Q FULL\n");
	else{
		q[++rear]=ele;
		if(front==-1)
			front=0;
	}
}

void dequeue(){
	int ele;
	if(front==-1)
		printf("Q Empty!\n");
	else{
		ele=q[front];
		if(front==rear)
			front=rear=-1;
		else 
			front=front+1;
	}
}

void display(){
	int i;
	if(front==-1)
		printf("Q is Empty!");
	else{
		for(i=front;i<=rear;i++)
			printf("\t%d",q[i]);
	}
}

void main(){
	int ch,ele;
	while(1){
	printf("++++++++++++\n");
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
		dequeue();
		break;		
		
	case 3:
		display();
		break;
	case 4:
		exit(0);
}
}
}
