//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
public:

bool isSafe(int mid,vector<int>&stalls,int n,int k){
    int cowcount=1;
    int lastpos=stalls[0];
    
    for(int i=0;i<stalls.size();i++){
        if(stalls[i]-lastpos>=mid){
            cowcount++;
            if(cowcount==k) return true;
            lastpos=stalls[i];
        }
    }
    return false;
}

    int solve(int n, int k, vector<int> &stalls) {
    
        // Write your code here
        if(k>n) return -1;
        sort(stalls.begin(),stalls.end());
        int low=0;
        int high=*max_element(stalls.begin(),stalls.end())- *min_element(stalls.begin(),stalls.end());
        
        int ans=-1;
        
        while(low<=high){
            int mid = low+ (high-low)/2;
            
            if(isSafe(mid,stalls,n,k)){
                ans=mid;
                low=mid+1;
            }
            else
            high=mid-1;
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input

        int n, k;
        cin >> n >> k;

        vector<int> stalls(n);
        for (int i = 0; i < n; i++) {
            cin >> stalls[i];
        }
        // char ch;
        // cin >> ch;

        Solution obj;
        cout << obj.solve(n, k, stalls) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends