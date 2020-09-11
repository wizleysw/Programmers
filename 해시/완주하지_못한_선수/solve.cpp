#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    
    map<string, int> mapp;
    
    for(int i=0; i<participant.size(); i++){
        mapp[participant[i]]++;
    }
    
    for(int i=0; i<completion.size(); i++){
        mapp[completion[i]]--;
        if(mapp[completion[i]]<=0){
            mapp.erase(completion[i]);
        }
    }
    
    answer = mapp.begin()->first;
    return answer;
}
