#include <iostream>
#include <sys/time.h>
using namespace std;
int main() {
   
   long double num=800, fact = 1, i;
   // cout<<"Enter the number";
   // cin>>num; 
   struct timeval t1,t2;
   struct timezone z1,z2;
   cout<<"Factorial of "<< num <<" is ";
   gettimeofday(&t1,&z1);
   for(i=1; i<=num; i++){
   fact = fact * i;
   }
   cout<<fact;
   gettimeofday(&t2,&z2);
   cout<<endl;
    cout<<"."<<endl;
    cout<<"."<<endl;
    cout<<"."<<endl;
    cout<<"Difference->"<<t2.tv_sec-t1.tv_sec<<"and"<<t2.tv_usec-t1.tv_usec<<endl;
   return 0;
}
