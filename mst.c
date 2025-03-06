#include<stdio.h>
#include<limits.h>
int main()
{
int i,j,k,n,source;
int w[50][50];
int visited[20];
int min,total=0,ev=0,sv=0;
printf("Enter no of vertices:\n");
scanf("%d",&n);
printf("Enter the cost matrix:\n");
for(i=1;i<=n;i++)
{
for(j=1;j<=n;j++)
scanf("%d",&w[i][j]);
}
printf("Enter the source vertex to start:\n");
scanf("%d",&source);
for(i=1;i<=n;i++)
visited[i]=0;
visited[source]=1;
printf("Minimum weight edges selectedfor spanning tree are:\n");
for(i=1;i<n;i++)
{
min=INT_MAX;
for(j=1;j<=n;j++)
{
if(visited[j]==1)
{
for(k=1;k<=n;k++)
{
if(visited[k]!=1&&w[j][k]<min)
{
sv=j;
ev=k;
min=w[j][k];
}
}
}
}
total+=min;
visited[ev]=1;
printf("%d-->%d Cost: %d\n",sv,ev,min);
}
printf("The total cost of main spanning tree is %d\n",total);
return 0;
}

