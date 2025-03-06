#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int i,j;
int partition(int a[],int low,int high)
{
int pivot=a[low];
int i=low+1;
int j=high;
int temp;
while(1)
{
while(i<=high&&a[i]<=pivot)
i++;
while(a[j]>pivot)
j--;
if(i<j)
{
temp=a[i];
a[i]=a[j];
a[j]=temp;
}
else
{
temp=a[low];
a[low]=a[j];
a[j]=temp;
return j;
}
}
}
void quick(int a[],int low,int high)
{
if(low<high)
{
int pi=partition(a,low,high);
quick(a,low,pi-1);
quick(a,pi+1,high);
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
a[i]=rand()%50000;
}
clock_t start=clock();
quick(a,0,n-1);
printf("Sorted Elements are:");
for(i=0;i<10;i++)
printf("%d ",a[i]);
clock_t end=clock();
double time=((double)(end-start))/CLOCKS_PER_SEC;
printf("\nTime taken for sorting : %f seconds\n",time);
return 0;
}
