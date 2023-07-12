#include <iostream>
#include <math.h>
#include <sys/time.h>
using namespace std;
int main(){
int num=30;
struct timeval t1,t2;
struct timezone z1,z2;
cout << "The Constant : " ;
// cout<<"Enter the value ";
// cin>>num;
long double T=((pow((-1),(num+1))) + (pow((4),(num))));
gettimeofday(&t1,&z1);
cout<<T;
gettimeofday(&t2,&z2);
    cout<<endl;
cout<<"."<<endl;
cout<<"."<<endl;
cout<<"."<<endl;
cout<<"Difference->"<<t2.tv_sec-t1.tv_sec<<"and"<<t2.tv_usec-t1.tv_usec<<endl;
   return 0;
}

