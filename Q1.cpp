#include <iostream>
#include <sys/time.h>
using namespace std;
long double T(int num) {
   if(num==1) {
      return 5;
   }
   else if(num==0){
   return 0;
   }
   else {
      return((3*T(num-1))+(4*T(num-2)));
   }
}

int main() {
   int n=30 ;
   
   // cout << "Enter the number: ";
   // cin >> n;
   struct timeval t1,t2;
   struct timezone z1,z2;
cout << " Series : ";
gettimeofday(&t1,&z1);
      cout << T(n);
gettimeofday(&t2,&z2);
   cout<<endl;
cout<<"."<<endl;
cout<<"."<<endl;
cout<<"."<<endl;
cout<<"Difference->"<<t2.tv_sec-t1.tv_sec<<"and"<<t2.tv_usec-t1.tv_usec<<endl;
   return 0;
}
