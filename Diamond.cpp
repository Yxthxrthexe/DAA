#include<iostream>
#include<sys/time.h>
using namespace std;
int max(int x,int y){
    return (x>y)?x:y;}
int diamond_n_bag(int n,int val[][2],int c){
	if(n==0||c==0){return 0;}
	if(val[n][0]>c){return diamond_n_bag(n-1,val,c);}
	else{
		return max(diamond_n_bag(n-1,val,c),diamond_n_bag(n-1,val,c-val[n][0])+val[n][1]);
	}
}
int main(){
	struct timeval t1, t2;
    struct timezone z1, z2;
	int diamonds[8][2]={(6,11),(11,28),(2,2),(,(4,7),(25,31),(23,24),(31,33),(6,9)};
	int max_len=sizeof(diamonds)/sizeof(diamonds[0][0])/2;
	int weight;
	cout<<"Enter weight:";
	cin>>weight;
	gettimeofday(&t1, &z1);
	int val=diamond_n_bag(max_len,diamonds,weight);
	gettimeofday(&t2, &z2);
	cout<<"Time Difference in Second "<< t2.tv_sec- t1.tv_sec <<"Time Difference in Microsecond "<< t2.tv_usec - t1.tv_usec<<endl;
	cout<<"Maximum Value : "<< val<<endl;
	return 0;
}



