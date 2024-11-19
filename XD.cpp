#include<iostream>
#include <limits.h>

using namespace std;

class Solution {
public:
    int myAtoi(string s){
        
        long long ans=0;
        int op=1;
        bool flag=false;

        for(int i=0;i<s.length();i++){
            if(flag==false && s[i]==' ') continue;
         
            if(flag==false && (s[i]=='+' || s[i]=='-')){
                if(s[i]=='-') op=-1;
                flag=true;
            }

            else if(!(s[i]>='0' && s[i]<='9')) break;

            else{
                
                flag=true;
                ans*=10;
                ans+=(op*(s[i]-'0'));
                
                if(ans<INT_MIN) return INT_MIN;
                else if(ans>INT_MAX) return INT_MAX;
            
            }
        }
        return ans;
    }
};

int main(){
    
    string s = "+-21";
    Solution sol;
    cout << sol.myAtoi(s);
    
    return 0;
}
