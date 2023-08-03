class Solution {
public:
    string findlcs(string s1,string s2){
         int n=s1.length();
        int m=s2.length();
        
        string dp[n+1][m+1];
        for(int i=0;i<=n;i++){
            for(int j=0;j<=m;j++){
                if(i==0||j==0) dp[i][j]="";
                else if(s1[i-1]==s2[j-1]) dp[i][j]=dp[i-1][j-1]+s1[i-1];
                else dp[i][j]=dp[i][j-1].size()>dp[i-1][j].size()?dp[i][j-1]:dp[i-1][j];
            }
        }
        return dp[n][m];
    }
    string shortestCommonSupersequence(string str1, string str2) {
        string ans="";
        string lcs=findlcs(str1,str2);
        
        int p1=0,p2=0;
        for(char c:lcs){
            while(str1[p1]!=c){
                ans+=str1[p1++];
            }
            while(str2[p2]!=c)
                ans+=str2[p2++];
            
            ans+=c;
            ++p1;
            ++p2;
        }
        ans+=str1.substr(p1)+str2.substr(p2);
        return ans;
    }
};