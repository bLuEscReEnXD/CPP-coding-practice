#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        //cout << n;
        if(n==1) return matrix[0][0];

        for(int i=n-2;i>=0;i--){
            for(int j=0;j<n;j++){

                if(j!= 0 && j!= n-1)  matrix[i][j] += min(min(matrix[i+1][j], matrix[i+1][j-1]), matrix[i+1][j+1]);
                else if(j==0)         matrix[i][j] += min(matrix[i+1][j], matrix[i+1][j+1]);
                else                  matrix[i][j] += min(matrix[i+1][j], matrix[i+1][j-1]);

            }

        }

        return *min_element(matrix[0].begin(), matrix[0].end());
    }
};






int main(){

    vector<vector<int>> x = {{2,1,3},{6,5,4},{7,8,9}};

    cout << Solution().minFallingPathSum(x);

    return 0;
}
