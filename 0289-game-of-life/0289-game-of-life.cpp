class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        //0->0 0
        //1->1 1
        //0->1 2
        //1->0 3
        int n=board.size();
        int m=board[0].size();
        
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[0].size();j++)
            {
                int zeros=0,ones=0;
                vector<int> newx={0,0,1,1,1,-1,-1,-1};
                vector<int> newy={1,-1,0,1,-1,0,1,-1};
                
                for(int k=0;k<8;k++)
                {
                    if(i+newx[k]<n and i+newx[k]>=0 and j+newy[k]<m and j+newy[k]>=0)
                    {
                        if(board[i+newx[k]][j+newy[k]]==0 or board[i+newx[k]][j+newy[k]]==2)
                        {
                            zeros++;
                        }
                        else
                        {
                            ones++;
                        }
                    }
                }
                if(board[i][j]==0)
                {
                    if(ones==3)
                    {
                        board[i][j]=2;
                    }
                }
                else
                {
                    if(ones<2 or ones>3)
                    {
                        board[i][j]=3;
                    }
                }
            }
        }
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[0].size();j++)
            {
                if(board[i][j]==2)
                {
                    board[i][j]=1;
                }
                else if(board[i][j]==3)
                {
                    board[i][j]=0;
                }
            }
        }
        
    }
};