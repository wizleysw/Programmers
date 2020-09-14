#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <deque>

using namespace std;

vector<int> solution(vector<string> operations) {
    priority_queue<int, vector<int>, greater<>> min_heap;
    priority_queue<int, vector<int>, less<>> max_heap;
    deque<int> deq;
    
    for(int i=0;i<operations.size() ; i++){
        if(operations[i][0] == 'I'){
            int no = stoi(operations[i].substr(2));
            deq.push_back(no);
            sort(deq.begin(), deq.end());
        } else {    
            if(!deq.size()) continue;
            if(operations[i].size() == 4){
                deq.pop_front();
            } else {
                deq.pop_back();
            }   
        }
    }

    if(!deq.size()){
        return {0,0};
    }
    
    return {deq.back(), deq.front()};
}
