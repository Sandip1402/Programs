// given weight and value of items & total weight capacity. Get maximum value within
// given weight capacity
#include<bits/stdc++.h>
using namespace std;

// Type - 1 : single unit of each item available

// Recursion - O(2^n)
int knapsack_recur(int wt[], int val[], int cap, int n){
    if(n==0 || cap==0)
        return 0;
    if(wt[n-1]>cap)
        return knapsack_recur(wt,val,cap,n-1);
    else
        return max(knapsack_recur(wt,val,cap,n-1),val[n-1]+knapsack_recur(wt,val,cap-wt[n-1],n-1));
}

// DP - O(n * W)
int knapsack_dp(int wt[], int val[], int cap, int n) {
    int dp[n+1][cap+1];
    for(int i = 0; i <= n; i++){ dp[0][i] = 0; }
    for(int i = 0; i <= cap; i++){ dp[i][0] = 0; }

    // dp[..i][..j] stores max val from upto ith weight and j capacity
    
    for(int i=1; i<=n; i++){
        for(int j=1; j<=cap; j++){
            if(wt[i-1]>j || j >= (wt[i-1] * 2)){
                dp[i][j] = dp[i][j-1]; // take as it is
            }
            else{
                int x = j-wt[i-1];
                dp[i][j] = max(dp[i-1][j] , val[i-1]+dp[i-1][x]);
            }
        }
    }

    // for(int i = 0; i <= n; i++){
    //     for(int j = 0; j <= cap; j++){
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

    return dp[n][cap];
}

// Type - 2 : unlimited unit of each item available

int main()
{
    int wt[] = {4,5,1,2,3,2};
    int val[] = {1,2,3,4,5,6};
    int cap = 17;

    cout<<knapsack_recur(wt, val, cap, 6)<<endl;
    cout<<knapsack_dp(wt, val, cap, 6)<<endl;
    return 0;
}