//{ Driver Code Starts
// Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template in C++

class Solution 
{
    public:
    
    bool isPossible(int A[],int mid,int n,int m){
        int studentcount=1;
        int pagesum=0;
        
        for(int i=0;i<n;i++){
            if(pagesum+A[i]<=mid) pagesum+=A[i];
            else
            {
                studentcount++;
                if(studentcount>m || A[i]>mid)
                return false;
                
                pagesum=A[i];
            }
        }
        return true;
    }
    //Function to find minimum number of pages.
    int findPages(int A[], int N, int M) 
    {
        //code here
        if(M>N) return -1;
        int low=0;
        int high= accumulate(A,A+N,0);
        int ans;
        
        while(low<=high){
            int mid = low + (high-low)/2;
            if(isPossible(A,mid,N,M)){
                ans=mid;
                high=mid-1;
            }
            else
            low=mid+1;
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}

// } Driver Code Ends