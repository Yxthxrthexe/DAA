#include<iostream>
#include <sys/time.h>
using namespace std;
class MergeSort{
    public:
    int arr[5];
    void splitSort(int a[], int lowerIndex, int upperIndex){
        if(lowerIndex<upperIndex){
        int  mid=(lowerIndex+upperIndex)/2;
        splitSort(a,lowerIndex,mid);//i
        splitSort(a,mid+1,upperIndex);//j
        mergeSort(a,lowerIndex,mid,upperIndex);
        }
    }
    void mergeSort(int a[],int lowerIndex,int mid,int upperIndex){
        int i=lowerIndex;
        int j=mid+1;
        int k=lowerIndex;
        while(i<=mid && j<=upperIndex){
            if(a[i]<=a[j]){
            arr[k]=a[i];
            i++;
            }
            else{
                arr[k]=a[j];
                j++;
            }
            k++;
        }
        if(i>mid){
            while(j<=upperIndex){
            arr[k]=a[j]; 
            j++;
            k++;
            }
        }
        else{
            while(i<=mid){
            arr[k]=a[i];
            i++;
            k++;
            }
        }
        for(k=lowerIndex;k<=upperIndex;k++){
           a[k]=arr[k];
        }
        
    }
    void print(int arr[]){
        for( int i=0; i<499; i++){
            cout<<arr[i]<<", ";

        }
        cout<<endl;
    }
};
int main(){
MergeSort m1; 
 int arr[500];
    int l=sizeof(arr)/sizeof(arr[0]);
    cout<<"Ascending";
     for (int i=0;i<l;i++){
     arr[i]=i;
     }
    for(int j=0; j<500 ;j++){
    arr[j]=rand()%500;
}
struct timeval t1,t2;
struct timezone z1,z2;
gettimeofday(&t1,&z1);
    m1.splitSort(arr,0,499); 
gettimeofday(&t2,&z2);
   cout<<endl;
cout<<"Difference->"<<t2.tv_sec-t1.tv_sec<<"and"<<t2.tv_usec-t1.tv_usec<<endl; 
m1.print(arr);   
return 0;
}
