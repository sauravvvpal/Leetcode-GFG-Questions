//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//Back-end complete function Template for C++

class Solution {
  public:
    int findTargetSumWays(vector<int>&A ,int target) {
        //Your code here
        int sum1=accumulate(A.begin(),A.end(),0);
        
        if(abs(target)>sum1 || (sum1+target)%2!=0)
            return 0;
        
        int sum=(target+sum1)/2;
        int N=A.size();
        
        int dp[N+1][sum+1];
        
       dp[0][0]=1;
        for(int j=1;j<=sum;j++){
            dp[0][j]=0;
        }
        
        for(int i=1;i<=N;i++){
            for(int j=0;j<=sum;j++){
                if(A[i-1]>j)
                dp[i][j]=dp[i-1][j];
                
                else
                dp[i][j]= dp[i-1][j] + dp[i-1][j-A[i-1]];
            }
        }
        return dp[N][sum];
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;
        vector<int>arr(N);
        
        for(int i=0 ; i<N ; i++){
            cin>>arr[i];
        }
        int target;
        cin >> target;

        Solution ob;
        cout<<ob.findTargetSumWays(arr,target);
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends