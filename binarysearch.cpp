#include<iostream>
using namespace std;

int main(){

 int n, i, j, ele;
 cout<<"Enter size"<<endl;
 cin>>n;
 int arr[n];
 cout<<"Enter elements"<<endl;
 for(i=0;i<n;i++){

   cin>>arr[i];

 }
 cout<<"Enter index to find"<<endl;
 cin>>ele;

 int start=0;
  int end=n-1;

 while(start<=end){

  int mid=(start + end)/2;

  if(arr[mid]==ele){
  cout<<mid;
  break;
  }
  if(arr[mid]<ele){
     start=mid+1;
  }
  if(arr[mid]>ele){
     end = mid-1;
  }

 }

}
