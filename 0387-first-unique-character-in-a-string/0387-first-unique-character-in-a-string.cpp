class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char,int>mp;
        for(int i=0;i<s.length();i++){
            mp[s[i]]++;
        }
        
        int ans;
        
        bool check=0;
        
        for(int i=0;i<s.size();i++){
            if(mp[s[i]]==1){
                check=1;
                ans=i;
                break;
            }
        }
        if(check==1)
        return ans;
        else
            return -1;
    }
};