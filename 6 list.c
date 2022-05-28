#include<stdio.h>
#include<stdlib.h>

typedef struct node* listptr;

struct node{
	int data;
	listptr link;
};

listptr First=NULL;
listptr getnode(){
	listptr new;
	new=(listptr)malloc(sizeof(struct node));
	return new;
}

void insertbegin(int ele){
	listptr new;
	new=getnode();
	new->data=ele;
	new->link=NULL;
	if(First==NULL){
		First=new;
	}else{
		new->link=First;
		First=new;
	}
}

void display(){
	listptr temp;
	if(First==NULL){
		printf("List EMpty!");exit(0);
	}
	/*for(temp=First;(temp->link)!=NULL;temp=temp->link){
		printf("%d\t",temp->data);
	}*/
	temp=First;
	while(temp->link!=NULL){	
		printf("%d\n ",temp->data);
		temp=temp->link;
	}
	printf("%d\n ",temp->data);
}

void insertend(int ele){
	listptr new,temp;
	new=getnode();
	new->data=ele;
	new->link=NULL;
	if(First==NULL){
		First=new;
	}else{	
		temp=First;
		while((temp->link)!=NULL){
			temp=temp->link;
		}
		temp->link=new;
	}
}

void deletebegin(){
	listptr temp;	
	if(First==NULL){
		printf("List EMpty!\n");
		return;		
	}	
	else{
		temp=First;
		First=First->link;
		free(temp);
	}
}

void deleteend(){
	listptr temp,prev;	
	if(First==NULL){
		printf("List EMpty!\n");
		exit(0);
	}
	temp=First;
	if(First->link==NULL)
	{
	      First=NULL;free(temp);
	}  	
	else{
		prev=First;
		while(temp->link!=NULL){
			prev=temp;		
			temp=temp->link;
		}
		prev->link=NULL;
		free(temp);
	}
}

void deletespecified(int ele){
	listptr temp,prev;
	temp=First;
	if(First==NULL){
		printf("List Empty!\n");
	}else if(First->data==ele)
	{	
		if(First->link!=NULL)
			First=First->link;
		else
			First=NULL;
	}else{
		while(temp->data!=ele && temp->link!=NULL){
			prev=temp;
			temp=temp->link;
		}
		if(temp->link==NULL && temp->data!=ele){
			printf("Specific Item not found!");
			return;
		}
		else if(temp->link!=NULL)
			prev->link=temp->link;
		else
			prev->link=NULL;
	}
	free(temp);
}

void insertspecified(int ele,int pos){
	listptr new=getnode();
	listptr prev,temp;
	temp=First;
	int cnt=1;
	new->data=ele;
	new->link=NULL;
	if(First==NULL){
		if(pos==1){
			First=new;
		}else{
			printf("Empty");
		}
	}else if(pos==1){
		new->link=First;
		First=new;
	}else{
		
		while(temp->link!=NULL){
			prev=temp;
			temp=temp->link;
			cnt++;
			if(cnt==pos){
				prev->link=new;
				new->link=temp;
				return;
			}
		}
		if(cnt+1 == pos){
		printf("Some");
			temp->link=new;
			temp=new;
		}
		else
			printf("Not Possible");
	}
}
void main(){
	int ch,ele,pos;
	while(1){
		printf("\n1.Insert Begin\t2Insert End\n3.Delete Begin\t4.Delete End\n5.Display\t6Delete Specified\t7.Exit");
		printf("Enter your choice:");
		scanf("%d",&ch);
		switch(ch){
		case 1:
			printf("Enter the element:\t");
			scanf("%d",&ele);
			insertbegin(ele);
			break;
		case 2:
			printf("Enter the element:\t");
			scanf("%d",&ele);
			insertend(ele);
			break;
		case 3:
			deletebegin();
			break;
		case 4:
			deleteend();
			break;
		case 5:
			display();
			break;
		case 6:
			printf("Enter the element to delete:\t");
			scanf("%d",&ele);
			deletespecified(ele);
			break;
		case 7:
			exit(0);
		case 8:
			printf("Enter the element to Insert:\t");
			scanf("%d",&ele);
			printf("Enter the position to Insert:\t");
			scanf("%d",&pos);
			insertspecified(ele,pos);
		}
	}
}

