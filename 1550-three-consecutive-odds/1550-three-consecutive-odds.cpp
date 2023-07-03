class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int cnt=0;
        
        for(int i=0;i<arr.size();i++){
            if(arr[i]%2==0)
                cnt=0;
            
            if(arr[i]%2==1){
                cnt++;
                if(cnt==3){ return true; break;
            }
            }
        }
        return false;
    }
};