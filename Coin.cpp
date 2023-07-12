#include <iostream>
#include <limits.h>
#include<sys/time.h>
using namespace std;

int main() {
    struct timeval t1, t2;
    struct timezone z1, z2;
    int coins[] = {1, 2, 5, 10, 20,50};
    int n = sizeof(coins)/sizeof(coins[0]);
    int sum = 1456382;
    
    int dp[sum+1];
    for(int i=0; i<=sum; i++) {
        dp[i] = INT_MAX; 
    }
    dp[0] = 0; 
    
    for(int i=0; i<n; i++) {
        for(int j=coins[i]; j<=sum; j++) {
            if(dp[j-coins[i]] != INT_MAX)
                gettimeofday(&t1, &z1);
                dp[j] = min(dp[j], dp[j-coins[i]]+1);
                gettimeofday(&t2, &z2);
        }
    }
    cout<<"Time Difference in Second "<< t2.tv_sec- t1.tv_sec <<"Time Difference in Microsecond "<< t2.tv_usec - t1.tv_usec<<endl;
    cout << "Minimum number of coins to make " << sum << " rupees: " << dp[sum] << endl;
    
    return 0;
}
