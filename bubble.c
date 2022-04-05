#include<stdio.h>

int a[10],n;
void bubblesort();
void bubblesort()
{
	int i,j,temp;
	for(i=0;i<n;i++)
		for(j=0;j<n-i-1;j++)
		{
			if(a[j]>a[j+1])
			{
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
		}	
}

void main(){
	int i;
	printf("Enter the number of elements:\t");
	scanf("%d",&n);
	printf("Enter the array elements:\t");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	bubblesort();
	printf("The sorted elements are:");
	for(i=0;i<n;i++)
		printf("%d\t",a[i]);
}

