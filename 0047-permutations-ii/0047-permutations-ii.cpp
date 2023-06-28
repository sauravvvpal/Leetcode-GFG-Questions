class Solution {
public:
    void permutations(int ind,vector<int>arr,int n,vector<vector<int>>&ans){
      if(ind==n){
          ans.push_back(arr);
          return ;
      }
      unordered_set<int>m;
      
      for(int i=ind;i<n;i++){
          if(m.find(arr[i])!=m.end()) continue;
          m.insert(arr[i]);
          swap(arr[ind],arr[i]);
          permutations(ind+1,arr,n,ans);
          swap(arr[ind],arr[i]);
      }
  }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
         vector<vector<int>>ans;
        int n=nums.size();
        permutations(0,nums,n,ans);
        sort(ans.begin(),ans.end());
        
        return ans;
    }
};