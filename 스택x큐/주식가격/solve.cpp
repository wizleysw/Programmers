#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

/**
REF
https://programmers.co.kr/questions/9454
https://mungto.tistory.com/6
 **/
vector<int> solution(vector<int> prices) {
    vector<int> answer(prices.size(), 0);

    stack<int> st;
    
    for(int i=0; i<prices.size(); i++){
        
        while(!st.empty()){
            int idx = st.top();
            if(prices[idx] > prices[i]){
                answer[idx] = i - idx;
                st.pop();
            } else {
                break;
            }
        }
        st.push(i);
    }
    
    while(!st.empty()){
        int idx = st.top();
        st.pop();
        
        answer[idx] = prices.size() - idx -1;
    }

    return answer;
}
