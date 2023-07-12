#include <iostream>
#include <sys/time.h>
using namespace std;
long double fib(int num) {
   if((num==1)||(num==0)) {
      return(num);
   }
   else {
      return(fib(num-1)+fib(num-2));
   }
}
int main() {
   int num=30 , i=0;
   
   // cout << "Enter the number of terms of series : ";
   // cin >> num;
   struct timeval t1,t2;
struct timezone z1,z2;
cout << "Fibonnaci Series : ";
gettimeofday(&t1,&z1);
   while(i < num) {
      cout << " " << fib(i);
      i++;
   }
   
   gettimeofday(&t2,&z2);
   cout<<endl;
cout<<"."<<endl;
cout<<"."<<endl;
cout<<"."<<endl;
cout<<"Difference->"<<t2.tv_sec-t1.tv_sec<<"and"<<t2.tv_usec-t1.tv_usec<<endl;
   return 0;
}
