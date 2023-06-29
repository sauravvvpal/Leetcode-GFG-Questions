//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std;

// } Driver Code Ends
class Solution{
public:

     bool ishappy(int n){
         if(n<10){
             if(n==1 || n==7){
                 return true;
             }
             else
             return false;
         }
         
         long long int sum=0;
         while(n>0){
             int d=n%10;
             sum+=d*d;
             n/=10;
         }
         return ishappy(sum);
     }
    int nextHappy(int N){
        // code here
        while(N++){
            if(ishappy(N))
            break;
        }
        return N;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        Solution ob;
        cout << ob.nextHappy(N) << endl;
    }
    return 0; 
}
// } Driver Code Ends