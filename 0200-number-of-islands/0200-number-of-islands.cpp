class Solution {
public:
    void bfs(vector<vector<char>> grid, int i,int j,vector<vector<bool>>& visited)
    {
        visited[i][j]=true;
        queue<pair<int,int>> q;
        q.push({i,j});
        
        int m=grid.size();
        int n=grid[0].size();
        
        while(!q.empty())
        {
            int x=q.front().first;
            int y=q.front().second;
            q.pop();
            
            if(x+1<m and grid[x+1][y]=='1' and !visited[x+1][y])
            {
                visited[x+1][y]=true;
                q.push({x+1,y});
            }
            
            if(y+1<n and grid[x][y+1]=='1' and !visited[x][y+1])
            {
                visited[x][y+1]=true;
                q.push({x,y+1});
            }
            
            if(x-1>=0 and grid[x-1][y]=='1' and !visited[x-1][y])
            {
                visited[x-1][y]=true;
                q.push({x-1,y});
            }
                        
            if(y-1>=0 and grid[x][y-1]=='1' and !visited[x][y-1])
            {
                visited[x][y-1]=true;
                q.push({x,y-1});
            }
                
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int count=0;
        vector<vector<bool>> visited(m,vector<bool>(n,false));
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]=='1' and !visited[i][j])
                {
                    count++;
                    bfs(grid,i,j,visited);
                }
            }
        }
        return count;
    }
};