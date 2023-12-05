#include<iostream>
using namespace std;
void merge(int arr[],int left,int mid,int right)
{
int n1=mid-left+1;
int n2=right-mid;
int leftarray[n1],rightarray[n2];
for(int i=0;i<n1;i++)
{
leftarray[i]=arr[left+i];
}
for(int j=0;j<n2;j++)
{
rightarray[j]=arr[mid+1+j];
}
int i=0,j=0,k=left;
while(i<n1 && j<n2)
{
if(rightarray[j]>leftarray[i])
{
arr[k]=leftarray[i];
k++;
i++;
}
else
{
arr[k]=rightarray[j];
j++;
k++;
}
}
while(i<n1)
{
arr[k]=leftarray[i];
i++;
k++;
}
while(j<n2)
{
arr[k]=rightarray[j];
k++;
j++;
}
}
void print(int arr[],int size)
{
for(int i=0;i<size;i++)
{
cout<<arr[i]<<" ";
}
}
void mergesort(int arr[],int left,int right)
{
if(right>left)
{
int mid=left+(right-left)/2;
mergesort(arr,left,mid);
mergesort(arr,mid+1,right);
merge(arr,left,mid,right);
}
}
int main()
{
int arr[5]={9,0,7,5,1};
mergesort(arr,0,4);
print(arr,5);

}
