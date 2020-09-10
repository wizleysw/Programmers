#include <string>
#include <vector>
#include <iostream>
#include <stack>

using namespace std;

string solution(string p) {    
    if(!p.size()) return "";
    string answer = "";
    
    stack<char> st;
    
    string left = "";
    string right = "";
    
    int left_cnt = 0;
    int right_cnt = 0;
    
    int mid = 0;
    bool flag = true;
    for(int i=0; i<p.size(); i++){
        if(p[i] == '('){
            left_cnt++;
            st.push(p[i]);
        }
        else{
            right_cnt++;
            if(!st.empty()) st.pop();
            else flag = false;
        }
        
        left += p[i];
        
        if(left_cnt && right_cnt && left_cnt == right_cnt){
            mid = i+1;
            break;
        }
    }
    
    // STEP 2
    for(int i=mid; i<p.size(); i++){
        right += p[i];
    }

    // STEP 3
    if(flag){
        answer += left;
        answer += solution(right);
    }
    
    // STEP 4
    else {
        // STEP 4-1
        answer = "(";
        // STEP 4-2
        answer += solution(right);
        
        // STEP 4-3
        answer += ")";
        
        // STEP 4-4
        string tmp2 = "";
        for(int t=1; t<left.size()-1; t++){
            if(left[t] == '('){
                tmp2 += ')';
            } else {
                tmp2 += '(';
            }
        }
        
        answer += tmp2;        
    }

    return answer;
}
