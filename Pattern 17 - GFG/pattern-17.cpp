//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution {
  public:
    void printTriangle(int n) {
        // code here
         for(int i=1;i<=n;i++){
             for(int j=0;j<n-i;j++){
                 cout<<" ";
             }
            for(int j=0;j<i;j++){
                char ab='A'+j;
                cout<<ab;
            }
            if(i>1){
            for(int j=i-2;j>=0;j--){
                char ab='A'+j;
                cout<<ab;
            }
            }
            cout<<endl;
        }
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        Solution ob;
        ob.printTriangle(n);
    }
    return 0;
}
// } Driver Code Ends