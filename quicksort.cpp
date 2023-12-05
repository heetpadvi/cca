#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void swap(int &a,int &b)
{
int temp=a;
a=b;
b=temp;
}
int partition(int arr[],int low,int high)
{
int pivot=arr[high];
int i=low-1;
for(int j=low;j<high;j++)
{
if(arr[j]<pivot)
{
i++;
swap(arr[i],arr[j]);
}
}
swap(arr[i+1],arr[high]);
return (i+1);
}
void quicksort(int arr[],int low,int high)
{
if(high>low)
{
int index=partition(arr,low,high);
quicksort(arr,low,index-1);
quicksort(arr,index+1,high);
}

}
void print(int arr[],int size)
{
for(int i=0;i<size;i++)
{
cout<<arr[i]<<" ";
}

}
int main()
{
int arr[5]={7,2,4,9,3};

quicksort(arr,0,4);
print(arr,5);


}
