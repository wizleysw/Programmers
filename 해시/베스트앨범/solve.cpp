#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <map>

using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    
    map<string,int> total;
    map<string,int> record;
    vector<vector<pair<int,int>>> track(101);
    
    int record_id = 0;
    for(int i=0; i<genres.size(); i++){
        if(!total[genres[i]]){
            record[genres[i]] = record_id;
            record_id++;
        }
        int idx = record[genres[i]];
        track[idx].push_back(make_pair(plays[i], i));
        total[genres[i]] += plays[i];
    }
    
    priority_queue<pair<int,string>, vector<pair<int,string>>, less<>> pq;
    for(auto t: total){
        pq.push(make_pair(t.second, t.first));
    }
    
    while(!pq.empty()){
        string name = pq.top().second;
        int idx = record[name];
        pq.pop();
    
        sort(track[idx].begin(), track[idx].end(),[](pair<int,int> &a, pair<int,int> &b){
            if(a.first != b.first) return a>b;
            return a.second < b.second;
        });
        
        if(track[idx].size() == 1){
            answer.push_back(track[idx][0].second);
        } else {
            for(int i=0; i<2; i++){
                answer.push_back(track[idx][i].second);
            }
        }
    }
    return answer;
}
