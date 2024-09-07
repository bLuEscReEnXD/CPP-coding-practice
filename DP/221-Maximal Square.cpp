#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {

        int maxVal = 0;
        int row = matrix.size();
        int col = matrix[0].size();

        vector<vector<int>> DP(row, vector<int>(col,0));

        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){

                if(matrix[i][j] == '1'){
                    if(i==0 || j==0){

                        DP[i][j] = 1;


                    }else{

                        DP[i][j] = min({DP[i-1][j],DP[i-1][j-1],DP[i][j-1]})+1 ;
                    }

                }else {

                    DP[i][j] = 0;

                }
                maxVal = max(maxVal, DP[i][j]);
            }
        }


        return maxVal * maxVal;

    }
};


int main(){

    vector<vector<char>> DP = {{'1'}};

    cout << Solution().maximalSquare(DP);
    return 0;
}
