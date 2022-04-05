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
 {      First=NULL;free(temp);
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
	int counter=0,count=0;
	listptr temp,prev;
	temp=First;
	listptr new;
	new=getnode();
	new->data=ele;
	new->link=NULL;
	/*while(temp->link!=NULL){
		counter++;
		temp=temp->link;
		printf("%d",counter);
	}*/
	if(First==NULL && pos==1){
		new->data=ele;
		new->link=NULL;
		First=new;
	}else{	printf("INside here");
		printf("Counter:%d\n",counter);
		while(count!=pos&&temp->link!=NULL){
			prev=temp;
			temp=temp->link;
			count++;
			printf("%d\t",count);
		}
		if(pos==1){
			new->data=ele;
			new->link=First;
			First=new;
		}
		if(counter==pos){
			printf("Final if");
			new->data=ele;
			new->link=prev->link;
			prev->link=new;
		}
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

