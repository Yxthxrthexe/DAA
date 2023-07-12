#include<iostream>
#include <sys/time.h>
using namespace std;
class InsertionSort{
public:
void insertSort(int arr[], int num){
int i,temp,j;
for(int i=1;i<num;i++){
temp=arr[i];
j=i-1;
while(j>=0 && arr[j]>temp){
arr[j+1]=arr[j];
j--;
}
arr[j+1]=temp;
}
}
void print(int arr[], int num){
for(int i=0; i<num ; i++){
cout<<arr[i]<<";";
}
}
};
int main(){
InsertionSort i1;
int arr[500];
    int l=sizeof(arr)/sizeof(arr[0]);
    cout<<"Ascending";
    for (int i=0;i<l;i++){
     arr[i]=l-i;
     }
    for(int j=0; j<500 ;j++){
    arr[j]=rand()%500;
}
struct timeval t1,t2;
struct timezone z1,z2;
gettimeofday(&t1,&z1);
i1.insertSort(arr,500);
gettimeofday(&t2,&z2);
cout<<"Difference->"<<t2.tv_sec-t1.tv_sec<<"and"<<t2.tv_usec-t1.tv_usec<<endl;   
i1.print(arr,500); 
return 0;
}


