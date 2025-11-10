#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
int knapsackRecursive(int W, vector<int>wt,vector<int> val, int n,vector<vector<int>>& dp){
    if(n==0 || W==0) return 0;
    if(dp[n][W]!=-1) return dp[n][W];
    if(wt[n-1]>W){
        //Exclude
        dp[n][W] = knapsackRecursive(W,wt,val,n-1,dp);
    }
    else{
        //include
        int include= val[n-1] + knapsackRecursive(W-wt[n-1],wt,val,n-1,dp);
        
         //Exclude
        int exclude = knapsackRecursive(W,wt,val,n-1,dp);
        dp[n][W] = max(include,exclude);
    }
    return dp[n][W];
}

int main() {
    int n;
    cout << "Enter number of items: ";
    cin >> n;

    vector<int> val(n), wt(n);
    cout << "Enter values of items:\n";
    for (int i = 0; i < n; i++) cin >> val[i];
    cout << "Enter weights of items:\n";
    for (int i = 0; i < n; i++) cin >> wt[i];

    int W;
    cout << "Enter capacity of knapsack: ";
    cin >> W;

    // Initialize DP table with -1 (uncomputed)
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, -1));

    int maxValue = knapsackRecursive(W, wt, val, n, dp);

    cout << "\nMaximum value that can be obtained = " << maxValue << endl;

    return 0;
}