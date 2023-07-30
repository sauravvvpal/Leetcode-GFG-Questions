class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum1=accumulate(nums.begin(),nums.end(),0);
        
        if(abs(target)>sum1 || (sum1+target)%2!=0)
            return 0;
        
        int sum=(target+sum1)/2;
        int N=nums.size();
        
        int dp[N+1][sum+1];
        
       dp[0][0]=1;
        for(int j=1;j<=sum;j++){
            dp[0][j]=0;
        }
        
        for(int i=1;i<=N;i++){
            for(int j=0;j<=sum;j++){
                if(nums[i-1]>j)
                dp[i][j]=dp[i-1][j];
                
                else
                dp[i][j]= dp[i-1][j] + dp[i-1][j-nums[i-1]];
            }
        }
        return dp[N][sum];
        
    }
};