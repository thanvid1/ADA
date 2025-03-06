#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int i,j;
void selection(int a[],int n)
{
for( i=0;i<n-1;i++)
{
int min=i;
for( j=i+1;j<n;j++)
{
if(a[j]<a[min])
{
min=j;
}
}
if(min!=i)
{
int temp =a[i];
a[i]=a[min];
a[min]=temp;
}
}
}
int main()
{
int n;
printf("Enter the no of elements:");
scanf("%d",&n);
int a[n];
srand(time(NULL));
for( i=0;i<n;i++)
{
a[i]=rand()%1000;
}
clock_t start=clock();
selection(a,n);
printf("Sorted Elements are:");
for(i=0;i<10;i++)
printf("%d ",a[i]);
clock_t end=clock();
double time=((double)(end-start))/CLOCKS_PER_SEC;
printf("\nTime taken for sorting : %f seconds\n",time);
return 0;
}
