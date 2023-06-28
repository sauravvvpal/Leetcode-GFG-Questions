//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<vector<int>> result;
    void comsum(vector<int> &curr, int k, int n, int sum, int size, int index){
        if(size==k && sum == n){
            result.push_back(curr);
            return;
        }
        else if(size>k || sum>n)
            return;
        
        for(int i = index; i <= 9; i++){
            sum += i;
            curr.push_back(i);
            comsum(curr, k, n, sum, size+1, i+1);
            sum -= i;
            curr.pop_back();
        }
    }
    vector<vector<int>> combinationSum(int K, int N) {
        vector<int> curr;
        comsum(curr, K, N, 0, 0, 1);
        return result;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> K >> N;

        Solution obj;
        vector<vector<int>> ans = obj.combinationSum(K, N);
        sort(ans.begin(), ans.end());
        for (auto &arr : ans) {
            for (auto it : arr) cout << it << ' ';
            cout << endl;
        }
    }
    return 0;
}
// } Driver Code Ends