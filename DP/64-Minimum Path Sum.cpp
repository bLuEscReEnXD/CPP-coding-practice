class Solution {

    public:
        int minPathSum(vector<vector<int>>& grid) {

            int m = grid.size(), n = grid[0].size();

            vector<vector<int>> DP(m, vector<int>(n,-1));

            DP[0][0] = grid[0][0];

            for(int i = 0;i <m; i++){
                for(int j=0; j<n; j++){

                    if(i==0 && j==0) DP[0][0] = grid[0][0];

                    else if(i==0) DP[0][j] = grid[0][j] + DP[0][j-1];

                    else if(j==0) DP[i][0] = grid[i][0] + DP[i-1][0];

                    else DP[i][j] = grid[i][j] + min(DP[i][j-1], DP[i-1][j] );

                }
            }

            return DP[m-1][n-1];

        }
};

int main(){

    vector<vector<int>> grid = {{1,2,3},{4,5,6}};

    cout << Solution().minPathSum(grid);

    return 0;
