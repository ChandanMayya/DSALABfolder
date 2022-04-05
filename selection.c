#include<stdio.h>
void selectionsort();
int a[5],n;

void selectionsort(){
	int i,j,temp,min;
	for(i=0;i<n;i++)
	{
		min=i;
		for(j=i+1;j<n;j++)
		{	
			if(a[min]>a[j])
				min=j;
		}	
		temp=a[i];
		a[i]=a[min];
		a[min]=temp;
	}
}

void main(){
	int i;
	printf("Enter the number of elements:\t");
	scanf("%d",&n);
	printf("Enter the array elements:\t");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	selectionsort();
	printf("Sorted array is:");
	for(i=0;i<n;i++)
		printf("\t%d",a[i]);
}

