#include<stdio.h>   //binary search
int main(){
	int a[10],i,n,mid,low,high,se,temp=-1;
	printf("Enter the number of elements:");
	scanf("%d",&n);
	printf("Enter the array elements:");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	printf("Enter the search element:");
	scanf("%d",&se);
		low=0;
	high=n-1;
		
	while(low<=high)
          {
		
            mid=(low+high)/2;

            if(se==a[mid])
                 {
			printf("Item found at location: %d",mid);
			return 0;
		 }
		else if(se<a[mid])
                        {
			high=mid-1;
			}
		
		else    {
			low=mid+1;
			}
	
		
	  }
	
	printf("Search element not found");
}
	
