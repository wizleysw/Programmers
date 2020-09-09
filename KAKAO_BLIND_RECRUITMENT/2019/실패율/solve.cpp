#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int STAGE[501] = {0,};
vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    
    for(int s : stages){
        STAGE[s]++;
    }
    
    vector<pair<double, int>> result;
    
    int users = stages.size();
    for(int i=1; i<=N; i++){
        double failure = 0;
        users!=0 ? failure = (double)STAGE[i]/users : failure = 0;
        users -= STAGE[i];
        result.push_back(make_pair(failure, i));
    }
    
    sort(result.begin(), result.end(), [](pair<double,int> &a, pair<double,int> &b){
        if(a.first != b.first) return a.first >= b.first;
        return a.second < b.second;
    });
    
    for(auto r : result){
        answer.push_back(r.second);
    }
    
    return answer;
}
