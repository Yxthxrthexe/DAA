#include<iostream>
#include <sys/time.h>
using namespace std;
class QuickSort{
    public:
    int start, end,pivot,temp;
    int sort(int arr[], int lowerIndex, int upperIndex){
        pivot=arr[lowerIndex];
        start=lowerIndex;
        end=upperIndex;
        while(start<end){
        while(arr[start]<=pivot){
        start++;
        }
        while(arr[end]>pivot){
            end--;
        }
        if(start<end){
            swap(arr[start],arr[end]);
        }
        swap(arr[lowerIndex],arr[end]);
        }
        
        return end;
    }
    void quickSort(int arr[] ,int lowerIndex, int upperIndex){
        if(lowerIndex<upperIndex){
        temp=sort(arr,lowerIndex, upperIndex);
        quickSort(arr,lowerIndex,temp-1);
        quickSort(arr,temp+1,upperIndex);
        }
    }
    void print(int arr[]){
        for(int i=0; i<500; i++){
            cout<<arr[i]<<", ";
        }
        cout<<endl;
    }
};
int main(){
    QuickSort q1;
    int ans,lowerIndex,upperIndex;
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
            q1.quickSort(arr,0,499);
gettimeofday(&t2,&z2);
cout<<"Difference->"<<t2.tv_sec-t1.tv_sec<<"and"<<t2.tv_usec-t1.tv_usec<<endl;   
q1.print(arr); 
return 0;
}
