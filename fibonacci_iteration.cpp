#include <iostream>
#include <sys/time.h>
using namespace std;
void fib(int num) {
   long double a = 0, b = 1, c = 0;
   for (int i = 0; i < num; i++) {
      cout << a << " ";
      c = a + b;
      a = b;
      b = c;
   }
}
int main() {
   int num=30;
  
   // cout << "Enter the number : ";
   // cin >> num;
    struct timeval t1,t2;
struct timezone z1,z2;
cout << "The fibonacci series : " ;
gettimeofday(&t1,&z1);
   fib(num);
   gettimeofday(&t2,&z2);
    cout<<endl;
cout<<"."<<endl;
cout<<"."<<endl;
cout<<"."<<endl;
cout<<"Difference->"<<t2.tv_sec-t1.tv_sec<<"and"<<t2.tv_usec-t1.tv_usec<<endl;
   return 0;
}
