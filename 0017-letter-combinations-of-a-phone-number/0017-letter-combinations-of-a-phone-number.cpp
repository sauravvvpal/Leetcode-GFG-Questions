class Solution {
public:
    void solve(string digits,int index,string output,string map[],vector<string>&ans)
    {
        if(index>=digits.length()){
          ans.push_back(output);
            return ;
        }
        int number=digits[index]-'0';
        string value=map[number];
        
        for(int i=0;i<value.length();i++){
            output.push_back(value[i]);
            solve(digits,index+1,output,map,ans);
            output.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string>ans;
        if(digits.length()==0)
            return ans;
        
        string output="";
        int index=0;
        string map[10] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        solve(digits,index,output,map,ans);
        return ans;
        
    }
};