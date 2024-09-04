#include<bits/stdc++.h>
using namespace std;


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

            /*for(int i = 0;i <m; i++){
                for(int j=0; j<n; j++){
                    cout << DP[i][j] << '\t';
                }
                cout << endl;
            }*/
            return DP[m-1][n-1];

        }
};

    public:
        int minPathSum(vector<vector<int>>& grid) {

            int m = grid.size(), n = grid[0].size();

            //vector<vector<int>> DP(m, vector<int>(n,-1));

            //DP[0][0] = grid[0][0];

            for(int i = 1;i <m; i++){
                grid[0][i] += grid[0][i-1];
            }

            for(int i = 1;i <n; i++){
                grid[i][0] += grid[i-1][0];
            }

            for(int i = 1;i <m; i++){
                for(int j=1; j<n; j++){
                    grid[i][j] += min(grid[i][j-1], grid[i-1][j]);
                }
            }



            /*for(int i = 0;i <m; i++){
                for(int j=0; j<n; j++){
                    cout << DP[i][j] << '\t';
                }
                cout << endl;
            }*/
            return grid[m-1][n-1];

        }
};


int main(){

    vector<vector<int>> grid = {{1,2,3},{4,5,6}};

    cout << Solution().minPathSum(grid);

    return 0;
}
