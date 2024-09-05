#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {


        int m = triangle.size();
        int n = triangle[m-1].size();

        if(m==1) return triangle[0][0];


        vector<int*> ptr(n);


        for(int i=0;i<n;i++){
            ptr[i] = &triangle[m-1][i];

        }


        for(int i=m-2 ; i>=0;i--){
            for(int j=0; j<i+1; j++){

                   *ptr[j] = triangle[i][j] + min(*ptr[j], *ptr[j+1]);

                }
        }
        return *ptr[0];
    }
};



int main(){
    vector<vector<int>> x = {{2},{3,4},{6,5,7},{4,1,8,3}};
    cout << Solution().minimumTotal(x);


    return 0;
}
