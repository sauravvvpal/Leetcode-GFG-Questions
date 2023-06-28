//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution {
  public:
  
    void generateCombinations(int ind,vector<int>&ds,vector<vector<int>>&vec,vector<int>arr,int target){
        //Base Case
        if(ind==arr.size()){
            if(target==0){
                vec.push_back(ds);
            }
            return;
        }
        //check the target if target goes negative no need to call function again go to other one
        if(target>=arr[ind]){
            ds.push_back(arr[ind]);
            //pick the element Again
            generateCombinations(ind,ds,vec,arr,target-arr[ind]);
            ds.pop_back();
        }
        //not pick this element go to other one
        generateCombinations(ind+1,ds,vec,arr,target);
    }
    vector<vector<int> > combinationSum(vector<int> &A, int B) {
        vector<vector<int>> ans;
        vector<int> ds,newA;
        set<int>t;
        for(auto it:A){
            t.insert(it);
        }
        for(auto it:t){
            newA.push_back(it);
        }
        sort(newA.begin(),newA.end());
        generateCombinations(0,ds,ans,newA,B);
        return ans;
        
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> A;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            A.push_back(x);
        }   
        int sum;
        cin>>sum;
        Solution ob;
        vector<vector<int>> result = ob.combinationSum(A, sum);
   		if(result.size()==0){
   			cout<<"Empty";
   		}
        for(int i=0;i<result.size();i++){
            cout<<'(';
            for(int j=0;j<result[i].size();j++){
                cout<<result[i][j];
                if(j<result[i].size()-1)
                    cout<<" ";
            }
            cout<<")";
        }
        cout<<"\n";
    }
}	
// } Driver Code Ends