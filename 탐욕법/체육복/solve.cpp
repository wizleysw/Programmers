#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = n - lost.size();
    int cnt = 0;
    
    sort(lost.begin(), lost.end());
    sort(reserve.begin(), reserve.end());
      
    vector<int> reserved;
    for(int i=0; i<reserve.size(); i++){
        bool flag = true;
        
        for(int j=0; j<lost.size(); j++){
            if(reserve[i] == lost[j]){
                lost.erase(lost.begin()+j);
                cnt++;
                flag = false;
                break;
            }
        }
        
        if(flag) reserved.push_back(reserve[i]);
    }

    for(int i=0; i<reserved.size(); i++){
        int cur = reserved[i];
        
        for(int j=0; j<lost.size(); j++){
            if(lost[j] == cur-1){
                cnt++;
                lost.erase(lost.begin()+j);
                break;
            } else if(lost[j] == cur+1){
                cnt++;
                lost.erase(lost.begin()+j);
                break;
            }
        }   
    }
    answer += cnt;
    
    return answer;
}
