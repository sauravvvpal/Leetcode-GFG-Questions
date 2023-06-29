class Solution {
public:
    bool search(vector<vector<char>>& board,string &word,int n,int m,int i,int j,int k){
        if(k==word.size()){
            return true;
        }
        if(i<0 || j<0 || i==n || j==m || board[i][j]!=word[k]) return false;
        
        char ch=board[i][j];
        board[i][j]='#';
        bool op1= search(board,word,n,m,i+1,j,k+1);
        bool op2= search(board,word,n,m,i,j+1,k+1);
        bool op3= search(board,word,n,m,i-1,j,k+1);
        bool op4= search(board,word,n,m,i,j-1,k+1);
        
        board[i][j]=ch;
        
        return op1||op2||op3||op4;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n=board.size();
        int m=board[0].size();
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]==word[0]){
                    if(search(board,word,n,m,i,j,0))
                        return true;
                }
            }
        }
        return false;
    }
};