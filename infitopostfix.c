#include<stdio.h>
#include<ctype.h>


char infix[50],postfix[50],stack[50];
int top=-1;
void itop();
void push(char);
char pop();
int preced(char);

void itop()
{

	char ele;
	int k=0,i=0;
	while((ele=infix[i++])!='\0')
	{
		if(ele == '(')
			push(ele);
		else if(ele == ')'){
			while(stack[top]!='(')
				postfix[k++]=pop();
		}
		else if(isalnum(ele)){
			postfix[k++]=ele;
		}
		else{
			while(preced(ele)<=preced(stack[top])){
				postfix[k++]=pop();
			}
			push(ele);
		}
	}
	while(stack[top]!='$'){
		if((stack[top]=='(')||(stack[top]=='$'))
			pop();
		postfix[k++]=pop();
	}
}

void push(char ele){
	stack[++top]=ele;
}

char pop(){
	char ele;
	ele=stack[top--];
	return ele;
}

int preced(char ele){
	switch(ele){
		case '$':	return -1;
		case '(':	return 0;
		case '-':
		case '+':	return 1;
		case '*':
		case '/':	return 2;
	}
}

void main()
{
	printf("Enter the infix expression:\t");
	scanf("%s",infix);
	push('$');
	itop();
	printf("The postfix expression is:\t");
	puts(postfix);
}
