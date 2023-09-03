class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char>st;
        
     for(int i=0;i<s.length();i++){
         if(s[i]=='('){
             st.push(s[i]);
         }
         else if(s[i]==')' && (!st.empty() && st.top()=='(')){
                st.pop();
             }
                else
                st.push(s[i]);
     }   
                int cnt=0;
                while(!st.empty()){
                    cnt++;
                    st.pop();
                }
                
                return cnt;
    }
};