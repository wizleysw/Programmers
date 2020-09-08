#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

string solution(int n, int t, int m, vector<string> timetable) {
    string answer = "";
    
    priority_queue<int, vector<int>, greater<int>> pq;

    for(string t : timetable){
        int time = stoi(t.substr(0,2))*60 + stoi(t.substr(3,2));
        pq.push(time);
    }
    
    int bus_start = 9*60;
    int earliest = min(bus_start, pq.top()-1);
    int current_time = bus_start;
    
    int boarding = 0;
    
    int last_boarder = 0;
    int prev_last_boarder = 0;
    for(int bus=1; bus<=n; bus++){
        if(bus != 1) current_time += t;
        
        prev_last_boarder = last_boarder;
        
        int boarded = 0;
        int first_boarder = 0;
        if(pq.top() <= current_time) first_boarder = pq.top();
        
        int same_time_cnt = 0;
        
        while(!pq.empty()){
            if(boarded == m || pq.top() > current_time) break;
            
            last_boarder = pq.top();
            
            if(last_boarder == first_boarder) same_time_cnt++;
            
            pq.pop();
            
            boarded++;
        }
        
        // 해당 버스가 꽉 찬 경우
        if(boarded == m){
            // 맨 처음에 줄을 설 수 있는 경우
            if(first_boarder - prev_last_boarder >= 1){
                if(same_time_cnt < m){
                    boarding = last_boarder-1;
                } else {
                    boarding = first_boarder-1;
                }
            }
            // 맨 처음에 줄을 서지 못하는 경우
            else {
                // 가장 처음에 서는 경우
                if(boarding == 0){
                    boarding = earliest;
                }
                if(same_time_cnt < m){
                    boarding = last_boarder-1;
                }
            }
        }
        
        // 버스에 좌석이 남은 경우
        else {
            boarding = current_time;
        }
    }
    
    string h = to_string(boarding/60);
    string min = to_string(boarding%60);

    if(h.size() == 1){
        answer = "0" + h;        
    } else {
        answer = h;
    } 
    
    answer += ":";
    
    if(min.size() == 1){
        answer += "0" + min;
    } else {
        answer += min;
    }
    
    cout << answer << "\n";

    return answer;
    
}
