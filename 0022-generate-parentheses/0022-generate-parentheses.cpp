class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        findAll("(",1,0,ans,n);
        return ans;
    }
    
    void findAll(string s,int o,int c,vector<string>&ans,int n){
        
        if(s.length()==2*n){
            ans.push_back(s);
            return ;
        }

        if(o<n)
            findAll(s+"(",o+1,c,ans,n);
        if(c<o)
            findAll(s+")",o,c+1,ans,n);
    }
};