#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int solution(vector<int> food_times, long long k) {
    long long answer = 0;
    
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    
    for(int i=0; i<food_times.size(); i++){
        pq.push(make_pair(food_times[i], i));
    }
    
    int loop = 0;
    while(k>=pq.size() && !pq.empty()){
        k -= pq.size();
        loop++;
        
        while(pq.top().first<=loop && !pq.empty()){
            pq.pop();
        }
    }
    
    vector<pair<int,int>> after_reduction;
    
    while(!pq.empty()){
        after_reduction.push_back(make_pair(pq.top().second+1, pq.top().first));
        pq.pop();
    }
    
    sort(after_reduction.begin(), after_reduction.end());
    
    if(k>=after_reduction.size()) return -1;
    else{
        for(int i=0; i<after_reduction.size(); i++){
            if(k==0){
                answer = after_reduction[i].first;
                break;
            }
            k--;
        }
    }
    
    return answer;
}
