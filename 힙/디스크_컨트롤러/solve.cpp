#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int solution(vector<vector<int>> jobs) {
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
    
    for(auto job: jobs){
        pq.push(make_pair(job[0], job[1]));
    }
    
    vector<int> res;
    int time = 0;
    while(!pq.empty()){
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq2;
        
        if(time < pq.top().first){
            time = pq.top().first;
        }
        while(!pq.empty() && time>=pq.top().first){
            int start = pq.top().first;
            int duration = pq.top().second;
            pq.pop();
                
            pq2.push(make_pair(duration, start));
        }
    
        time += pq2.top().first;
        
        res.push_back(time - pq2.top().second);
        pq2.pop();
        
        while(!pq2.empty()){
            pq.push(make_pair(pq2.top().second, pq2.top().first));
            pq2.pop();
        }
    }
    
    int total = 0;
    for(auto r : res){
        total += r;
    }
    
    return total/res.size();
}
