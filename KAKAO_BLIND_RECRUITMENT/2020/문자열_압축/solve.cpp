#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int LENGTH = 0;
int MIN_LENGTH;

int solution(string S){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    LENGTH = S.length();
    MIN_LENGTH = LENGTH;

    for(int i=1; i<=LENGTH; i++){
        string result = "";
        queue<string> que;
        
        string cur = "";
        for(int j=0; j<LENGTH; j++){
            if(cur.length() == i){
                que.push(cur);
                cur = "";
            }

            cur += S[j];
        }
        
        if(cur.size() >= 1){
            que.push(cur);
        }
        
        string prev = que.front();
        que.pop();
        int cnt = 1;
        
        while(!que.empty()){
            string now = que.front();
            que.pop();
            
            if(prev == now){
                cnt++;
            } else {
                if(cnt == 1) result += prev;
                else result += to_string(cnt) + prev;
                prev = now;
                cnt = 1;
            }
        }
        
        if(cnt == 1) result += prev;
        else result += to_string(cnt) + prev;
        
        MIN_LENGTH = min(MIN_LENGTH, (int)result.length());
    }
    
    return MIN_LENGTH;
    
}
