#include<stdio.h>
int cost[10][10],n,mincost,v1=0,v2=0;

void doUnion(int root[],int v1,int v2){
	int temp=root[v2];
	for(int i=0;i<n;i++){
		if(root[i]==temp)
			root[i]=root[v1];
	}
}
void findMin(){
	int edgewt=99,i,j;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(cost[i][j]>0 && cost[i][j]<edgewt){
				edgewt=cost[i][j];
				v1=i;
				v2=j;
			}
		}
	}
}

void kruskal(){
	int i,edgewt;
	int root[n];
	for(i=0;i<=n;i++)
		root[i]=i;
	printf("\nEdges of mincost spanning tree are:\n");
	i=0;
	while(i!=n-1)	{
		findMin();
		edgewt=cost[v1][v2];
		cost[v1][v2]=cost[v1][v2]=0;
		if(root[v1]!=root[v2])	{
			printf("\n(%d%d)",v1,v2);
			doUnion(root,v1,v2);
			mincost+=edgewt;
			i++;
		}
	}
	printf("\nCost of mincost spanning tree: %d",mincost);	
}
void main()
{	
	int i,j;
	printf("Enter the no.of vertex:\t");
	scanf("%d",&n);
	printf("Enter the adjacency matrix:\n");
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			scanf("%d",&cost[i][j]);
	
	printf("The adjacency matrix:\n");
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++)
			printf("%d\t",cost[i][j]);
	printf("\n");
	}
	kruskal();
}	
