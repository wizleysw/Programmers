#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int solution(vector<string> lines) {
    vector<pair<int,bool>> works;
    int answer = 0;
    
    sort(lines.begin(), lines.end());
    
    for(int i=0; i<lines.size(); i++){
        int h = stoi(lines[i].substr(11, 2));
        int m = stoi(lines[i].substr(14, 2));
        int s = stoi(lines[i].substr(17, 2));
        int end = (h*60*60 + m*60 + s)*1000 + stoi(lines[i].substr(20, 3));
        double duration = stod(lines[i].substr(24, lines[i].size()-24-1));

        works.push_back(make_pair(end-duration*1000+1, true));
        works.push_back(make_pair(end+999, false));
    }

    sort(works.begin(), works.end(), [](pair<int,bool> &a, pair<int,bool> &b){
        if(a.first == b.first) return a.second > b.second;
        else return a.first < b.first;
    });
    
    int cnt = 0;
    for(int i=0; i<works.size(); i++){
        if(works[i].second){
            cnt++;
            answer = max(answer, cnt);
        }   
        else {
            
            cnt--;
        }
    }
        
    return answer;
}
