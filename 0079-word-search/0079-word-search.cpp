class Solution {
public:
    bool find(vector<vector<char>>& board ,string word, int ind,int i,int j)
    {
        if(ind==word.size())
        {
            return true;
        }
        if(i>=board.size() or j>=board[0].size() or i<0 or j<0 or board[i][j]!=word[ind])
        {
            return false;
        }
        if(board[i][j]==word[ind])
        {
            board[i][j]='$';
            if(find(board,word,ind+1,i+1,j))return true;
            if(find(board,word,ind+1,i,j+1))return true;
            if(find(board,word,ind+1,i-1,j))return true;
            if(find(board,word,ind+1,i,j-1))return true;
            board[i][j]=word[ind];
        }
        return false;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[0].size();j++)
            {
                
                if(find(board,word,0,i,j))
                {return true;}
                
            }
        }
        return false;
    }
};