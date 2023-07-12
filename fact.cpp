#include <iostream>
#include <sys/time.h>
using namespace std;
long double fact(int num){
if(num==1){
return 1;
}
else{
return num*fact(num-1);
}
}

int main(){
int num=800;

// cout<<"Enter the number";
// cin>>num;
struct timeval t1,t2;
struct timezone z1,z2;
cout<<"Factorial of" <<num<< "=" ;
gettimeofday(&t1,&z1);
cout<< fact(num);
gettimeofday(&t2,&z2);
cout<<endl;
cout<<"."<<endl;
cout<<"."<<endl;
cout<<"."<<endl;
cout<<"Difference->"<<t2.tv_sec-t1.tv_sec<<"and"<<t2.tv_usec-t1.tv_usec<<endl;
return 0;
}
