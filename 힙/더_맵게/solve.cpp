#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    priority_queue<int, vector<int>, greater<>> min_heap;
    
    for(auto i : scoville){
        min_heap.push(i);
    }
    
    int cnt = 0;
    while(min_heap.top() < K && min_heap.size() >= 2){
        int first = min_heap.top();
        min_heap.pop();
        
        int second = min_heap.top();
        min_heap.pop();
        
        int mixed = first + (second * 2);
        min_heap.push(mixed);
        cnt++;
    }
    
    if(min_heap.top() < K) return -1;
    
    return cnt;
}
