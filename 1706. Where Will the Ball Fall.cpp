class Solution {
public:
    int dp[105][105];
    int n,m;
    
    bool isvalid(int i,int j){
        if(i>=0&&i<n&&j>=0&&j<m)
            return true;
        return false;
    }
    
    int check(vector<vector<int>>& grid,int r,int c){
        if(r==n) // if row comparable to n means we reached our answer
            return c;
        if(isvalid(r,c)){
            if(grid[r][c]==1&&isvalid(r,c+1)&&grid[r][c+1]==1){
                
                if(dp[r+1][c+1]!=-2) return dp[r+1][c+1];// checking digonal value if exist than return answer
                else{
                    return dp[r+1][c+1] = check(grid,r+1,c+1);
                }
            }
            if(grid[r][c]==-1&&isvalid(r,c-1)&&grid[r][c-1]==-1){
                if(dp[r+1][c-1]!=-2) return dp[r+1][c-1];   // checking digonal value if exist than return answer
                else{
                    return dp[r+1][c-1] = check(grid,r+1,c-1);
                }
            } 
        }
        // if not exist than return -1;
        return -1;
    }
    
    vector<int> findBall(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        // assigning all value of dp -2;
        for(int i= 0;i<=n;i++){
            for(int j=0;j<=m;j++) dp[i][j] = -2;
        }
        //checking every col/ball
        vector<int>v(m);
        for(int i=0;i<m;i++)
            v[i] = check(grid,0,i);
        return v;
        
    }
};
