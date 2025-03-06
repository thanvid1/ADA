#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int i,j;

void merge(int a[],int low,int mid,int high)
{
int i=low,j=mid+1,k=low;
int c[1000000];
while(i<=mid&&j<=high)
{
if(a[i]<a[j])
{
c[k]=a[i];
i++;
}
else
{
c[k]=a[j];
j++;
}
k++;
}
while(i<=mid)
c[k++]=a[i++];
while(j<=high)
c[k++]=a[j++];
for(i=low;i<=high;i++)
a[i]=c[i];
}



void mergeSort(int a[],int low,int high)
{
if(low<high)
{
int mid=(low+high)/2;
mergeSort(a,low,mid);
mergeSort(a,mid+1,high);
merge(a,low,mid,high);
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
int low=0,high=n-1;
mergeSort(a,low,high);
printf("Sorted Elements are:");
for(i=0;i<10;i++)
printf("%d ",a[i]);
clock_t end=clock();
double time=((double)(end-start))/CLOCKS_PER_SEC;
printf("\nTime taken for sorting : %f seconds\n",time);
return 0;
}
