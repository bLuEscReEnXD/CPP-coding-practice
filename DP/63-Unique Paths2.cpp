class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {

        if(obstacleGrid[0][0] == 1) return 0;


        int m = obstacleGrid.size(), n = obstacleGrid[0].size();

        vector<vector<int>> DP(m+1,vector<int> (n+1,0));


        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){

                if(i==1 && j==1){
                    DP[1][1] = 1;
                    //cout << DP[1][1] << " ";
                }

                else if(obstacleGrid[i-1][j-1] == 0){

                    DP[i][j] = DP[i-1][j] + DP[i][j-1];
                    //cout << DP[i][j] << " ";

                }/*else{
                    cout << 'x' << " ";
                }*/
            }
            //cout << '\n';
        }

        return DP[m][n];
    }
};
