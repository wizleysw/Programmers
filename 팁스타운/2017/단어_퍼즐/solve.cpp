#include <iostream>
#include <string>
#include <vector>
using namespace std;

int solution(vector<string> strs, string t)
{
    vector<int> dp(t.size(), 987654321);
    
    for(int pos=0; pos<t.size(); pos++){
        for(auto word: strs){
            bool flag = true;
            for(int i=0; i<word.size(); i++){
                if(t[pos+i] != word[i]){
                    flag = false;
                    break;
                }
            }
            if(flag){
                if(pos == 0) dp[pos+word.size()-1] = 1;
                else dp[pos+word.size()-1] = min(dp[pos+word.size()-1], dp[pos-1]+1);
            }
        }
    }
    if(dp[t.size()-1] == 987654321) return -1;
    return dp[t.size()-1];
}
