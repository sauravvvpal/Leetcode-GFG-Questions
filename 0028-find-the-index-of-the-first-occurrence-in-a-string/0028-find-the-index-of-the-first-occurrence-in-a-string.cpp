class Solution {
public:
    int strStr(string haystack, string needle) {
        for(int i=0;i<haystack.length();i++){
            if(haystack.substr(i,needle.size())==needle)
                return i;
        }
        return -1;
    }
};