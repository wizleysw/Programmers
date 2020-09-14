#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;
vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    
    queue<int> st;
    for(int i=0; i<progresses.size(); i++){
        int remained = 100 - progresses[i];
        int days = remained / speeds[i];
        if(remained % speeds[i]) days++;
        
        st.push(days);
    }
    
    while(!st.empty()){
        int cnt = 1;
        int day = st.front();
        st.pop();
        
        while(!st.empty() && st.front()<= day){
            cnt++;
            st.pop();
        }
        
        answer.push_back(cnt);
    }
    
    return answer;
}
