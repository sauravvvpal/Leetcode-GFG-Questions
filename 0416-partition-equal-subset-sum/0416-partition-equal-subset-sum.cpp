class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int N=nums.size();
        int sum1=accumulate(nums.begin(),nums.end(),0);
        // agar sum odd hai to not possible
        if(sum1%2!=0) return 0;
        
        int sum=sum1/2;
        
        // baaki poora code subset sum wala hai
        
        int dp[N+1][sum+1];
        
        for(int i=0;i<=N;i++){
            dp[i][0]=1;
        }
        for(int j=1;j<=sum;j++){
            dp[0][j]=0;
        }
        
        for(int i=1;i<=N;i++){
            for(int j=1;j<=sum;j++){
                if(nums[i-1]>j)
                dp[i][j]=dp[i-1][j];
                
                else
                dp[i][j]= dp[i-1][j] || dp[i-1][j-nums[i-1]];
            }
        }
        return dp[N][sum];
        
    }
};