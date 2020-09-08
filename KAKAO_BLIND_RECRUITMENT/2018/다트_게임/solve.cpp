#include <stack>
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(string dartResult) {
    stack<string> st;
    
    string number = "";
    for(int i=0; i<dartResult.size(); i++){
        if(dartResult[i] >= '0' && dartResult[i] <= '9'){
            number += dartResult[i];
        }
        else{
            if(number.size()>=1){
                st.push(number);
                number = "";
            }
            
            if(dartResult[i] == 'S'){
                continue;
            }
            
            else if(dartResult[i] == 'D'){
                int now = stoi(st.top());
                st.pop();
                
                st.push(to_string(now*now));
            }
            
            else if(dartResult[i] == 'T'){
                int now = stoi(st.top());
                st.pop();
                
                st.push(to_string(now*now*now));
            }
            
            else if(dartResult[i] == '*'){
                int cnt = 0;
                stack<string> tmp;
                while(!st.empty()){
                    if(cnt == 2) break;
                    int now = stoi(st.top());
                    st.pop();
                    
                    tmp.push(to_string(now*2));
                    cnt++;
                }
                while(!tmp.empty()){
                    st.push(tmp.top());
                    tmp.pop();
                }
            }
            
            else if(dartResult[i] == '#'){
                stack<string> tmp;
              
                int now = stoi(st.top());
                st.pop();
                    
                st.push(to_string(now*-1));
            }
        }
    }
    
    int answer = 0;
    while(!st.empty()){
        int now = stoi(st.top());
        st.pop();
        
        answer += now;
    }
    
    return answer;
}
