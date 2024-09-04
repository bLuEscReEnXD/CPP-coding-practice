#include<bits/stdc++.h>
using namespace std;

class Solution {

    public:

        int uniquePaths(int m, int n) {

            vector<vector<int>> DP(m, vector<int>(n,1));

            for(int i=1;i<m;i++){
                for(int j=1;j<n;j++){
                    DP[i][j] = DP[i-1][j] + DP[i][j-1];
                }
            }

            return DP[m-1][n-1];
        }
};

int main(){

    int m=3;
    int n=7;

    cout << Solution().uniquePaths(m,n);

    return 0;
}


//Method below is inefficient Recursion (lack of return condition, no memoization, easy to stack overflow, no return value)

/*
    class Solution {

    private:
        int cnt=0;

    public:

        int pos(int x, int y, int m, int n){

            if(x==m-1 && y==n-1){
                //cout << x << " " << y << "\n";

                return cnt++;
            }else{

                if(x<m-1) pos(x+1,y,m,n);
                if(y<n-1) pos(x,y+1,m,n);

            }
            return -1;
        }



        int uniquePaths(int m, int n) {

            pos(0,0,m,n);
            return cnt;

        }
};
*/
