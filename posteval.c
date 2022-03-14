#include<stdio.h>
#include<ctype.h>
#include<math.h>

char postfix[50];
int stack[50];
int top=-1;
void push(int);
int pop();
int eval();

int eval()
{
	char symb;
	int i,op1,op2;
	while((symb=postfix[i++])!='\0')
	{
		if(isalnum(symb))
			push(symb-'0');
		else{
			op2=pop();
			op1=pop();
			switch(symb)
			{
				case '+':
					push(op1+op2);
					break;
				case '-':
					push(op1-op2);
					break;
				case '*':
					push(op1*op2);
					break;
				case '/':
					if(op2!=0){
					push(op1/op2);
					break;
					}else{printf("Out of loop");}
					
				case '^':
					push(pow(op1,op2));
					break;
				default :
					printf("Invalid Operator");
			}
		}
	}return(pop());
}

void push(int ele){
	stack[++top]=ele;
}

int pop(){
	int ele;
	ele=stack[top--];
	return ele;
}

void main()
{
	int val;
	printf("Enter the postfix expression:\t");
	scanf("%s",postfix);
	val=eval();
	printf("Result:\t %d",val);
}
