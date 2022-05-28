//Stack push and pop operations
#include<stdio.h>
#include<stdlib.h>

int stack[10],top=-1,n;
#define MAXSIZE 8
void main(){
	int i,c,ele;
	printf("Enter the number of elements:\t");
	scanf("%d",&n);
	while(1){
		printf("--------MENU---------\n");
		printf("1.PUSH\t2.POP\n3.DISPLAY\t4.EXIT\n");
		printf("Enter your choise:\t");
		scanf("%d",&c);
		switch(c){
			case 1:
				printf("Enter an element to push:\t");
				scanf("%d",&ele);
				if(top<MAXSIZE){
					stack[++top]=ele;
				}else{
					printf("Stack Overflow\n");
				}
				break;
			case 2:
				if(top!=-1){
					ele=stack[top--];
				}else{
					printf("Stack Underflow!\n");		
				}
				break;
			case 3:
				for(i=0;i<=top;i++)
					printf("%d\t",stack[i]);
				printf("\n");
				break;
			case 4:
				exit(0);
		}
	}
}

