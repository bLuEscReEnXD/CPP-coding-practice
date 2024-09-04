#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        // เนื่องจาก nums[i] ไม่สามารถนำมาคำนวณรวมกับ ตัวที่มีค่า +1 และ -1 ได้
        // วิธีคิดจึงสามารถใช้หลักการเดียวกับข้อ Rob ได้
        // ถ้ามีตัวซ้ำจะ + บวกทับไปเลย

        int n = *max_element(nums.begin(), nums.end());

        vector<int> newOrder(n+1); //auto set all element to zero

        for(int x: nums){
            newOrder[x] += x;

        }

        for(int i=2; i<=n; i++){
             newOrder[i] = max(newOrder[i-2] + newOrder[i], newOrder[i-1]);
             //cout <<  newOrder[i];
        }
        return newOrder[n];
    }
};


int main(){

    vector<int> nums = {3,2,4};

    cout << Solution().deleteAndEarn(nums);


    return 0;
}
