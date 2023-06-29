class Solution {
public:
    
    bool isHappy(int n) {
        if(n<10){
            if(n==1 || n==7) return true;
            else return false;
        }
        
        long long int sum=0;
        while(n>0){
            int d=n%10;
            sum+=d*d;
            n/=10;
        }
        return isHappy(sum);
    }
};