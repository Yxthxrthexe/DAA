#include <iostream>
#include <sys/time.h>
using namespace std;
 void heapify(int arr[] , int n, int i)
 {
 int big=i;
 int l= 2*i+1;
 int r= 2*i+2;
 if(l<n && arr[l]>arr[big] )
 {
 big=l;
 }
 if(r<n && arr[r]>arr[big])
 {
 big=r;
 }
 if(big!=i){
 swap(arr[i],arr[big]);
 heapify(arr,n,big);
 }
 }
 void heapsort(int arr[], int n)
 {
 for(int i=n/2 -1; i>=0; i--)
 {
 heapify(arr,n,i);
 }
 for (int i=n-1; i>0;i--){
 swap(arr[0],arr[i]);
 heapify(arr,i,0);
 }
 }
  
 void print (int arr[], int n){
 for(int i=0;i<n; i++)
 {
 cout<<arr[i];
 cout<<endl;
 }
 }
 
 int main()
 {
 int arr[500];
 int l=sizeof(arr)/sizeof(arr[0]);
cout<<"In descending";
//for (int i=0;i<l;i++){
//arr[i]=i;
//}
 for(int j=0; j<l ;j++){
    
    arr[j]=rand()%500;
}
 
struct timeval t1,t2;
struct timezone z1,z2;
gettimeofday(&t1,&z1);
 heapsort(arr,500);
 gettimeofday(&t2,&z2);
cout<<"Difference->"<<t2.tv_sec-t1.tv_sec<<"and"<<t2.tv_usec-t1.tv_usec<<endl;   
 print (arr,500);
 }
