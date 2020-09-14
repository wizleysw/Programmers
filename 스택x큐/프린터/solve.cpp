#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int solution(vector<int> priorities, int location) {

    deque<pair<int,int>> deq;
    
    for(int i=0; i<priorities.size(); i++){
        deq.push_back(make_pair(priorities[i],i));
    }
    
    int cnt = 1;
    while(true){
        int cur_prio = deq.front().first;
        int cur_idx = deq.front().second;
        
        bool has_larger_value = false;
        for(int i=1; i<deq.size(); i++){
            if(deq[i].first > cur_prio){
                has_larger_value = true;
                break;
            }
        }
        
        if(has_larger_value){
            deq.push_back(deq.front());
            deq.pop_front();
        } else {≈
            deq.pop_front();
            if(cur_idx == location) break;
            cnt++;
        }
        
    }
    
    return cnt;
}
