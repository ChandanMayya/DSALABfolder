#include<stdio.h>
int n,visited[10],count=0,k=0,top[10];
int a[10][10];

int dfs(int v)
{
	int w;
	count++;
	visited[v]=count;
	for(w=0;w<n;w++)
		if(a[v][w]==1 && visited[w]==0)
			dfs(w);
	printf("%d\t",v);
	top[k++]=v;
}
void main()
{
	int v,i,j;
	printf("Enter the no.of vertex:");
	scanf("%d",&n);
	printf("Enter the adjacency matrix:\n");
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			scanf("%d",&a[i][j]);
	printf("------Adjacency matrix------\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
			printf("%d\t",a[i][j]);
		printf("\n");
	}
	
	for(i=0;i<n;i++)
		visited[v]=0;
	printf("----------DFS Traversal--------\n");
	dfs(0);
	
	printf("----------Topological Sorting:--------\n");
	for(i=n-1;i>=0;i++)
		printf("%d\t",top[i]);
}	
