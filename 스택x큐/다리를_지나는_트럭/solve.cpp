#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    
    // 입장 시간, 무게
    queue<pair<int,int>> que;
    int que_weight = 0;
    
    int idx = 0;
    int sec = 1;
    while(idx < truck_weights.size()){
        while(!que.empty() && que.front().first+bridge_length == sec){
            que_weight -= que.front().second;
            que.pop();
        }

        if(que_weight<weight && truck_weights[idx]+que_weight<=weight){
            que.push(make_pair(sec,truck_weights[idx]));
            que_weight += truck_weights[idx];
            idx++;
        }
        sec++;
    }
    
    while(que.size()>1){
        que.pop();
    }
    return que.front().first + bridge_length;
}
