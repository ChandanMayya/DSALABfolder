#include<stdio.h>   //Linear search
void main(){
	int a[10],se,n,i,temp;
	printf("Enter the number of elements:");
	scanf("%d",&n);
	printf("Enter the array elements:");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	printf("Enter the search element:");
	scanf("%d",&se);
	for(i=0;i<n;i++)
		if(a[i]==se)
			temp=i;
	if(temp!=0)
		printf("The element has been found at location: %d",temp);
	else
		printf("Search element not found");
}
