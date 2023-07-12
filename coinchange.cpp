#include<iostream>
#include<sys/time.h>
using namespace std;
int make_change(int val[],int Amount,int n){
	if(Amount==0 || n==0){return 0;}
	int minreq_coin;
	int z = Amount/val[n-1];
	if(Amount>=val[n-1]){
	minreq_coin=make_change(val,Amount-z*val[n-1],n-1)+z;
	}
	else{
		minreq_coin=make_change(val,Amount,n-1)+0;
	}
	return minreq_coin;
}
int main(){
    struct timeval t1, t2;
    struct timezone z1, z2;
	int coin[]={1,2,5,10,20,50,100,200,500,2000};
	int n=sizeof(coin)/sizeof(coin[0]);
	cout<<"No. of coins "<<n<<endl;
	int Amount;
	cout<<"Enter Amount:";
	cin>>Amount;
    gettimeofday(&t1, &z1);
	int minreq_coin=make_change(coin,Amount,n);
    gettimeofday(&t2, &z2);
    cout<<"Time Difference in Second "<< t2.tv_sec- t1.tv_sec <<"Time Difference in Microsecond "<< t2.tv_usec - t1.tv_usec<<endl;
	cout<<"Required min number of coins : "<<minreq_coin<<endl;
	return 0;
}
