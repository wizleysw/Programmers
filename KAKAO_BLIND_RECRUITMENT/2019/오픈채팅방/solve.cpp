#include <string>
#include <vector>
#include <iostream>
#include <string.h>
#include <map>

using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    vector<pair<string,string>> info;
    map<string, string> mapp;
    
    for(auto r : record){
        int block = 0;
        string command = "";
        string uid = "";
        string nickname = "";
        string buffer = "";
        for(int i=0; i<r.size(); i++){
            if(r[i] == ' '){
                if(block == 0){
                    command = buffer;
                } else if(block == 1){
                    uid = buffer;
                }
                buffer = "";
                block++;
            } else {
                buffer += r[i];
            }
        }
        if(command == "Leave"){
            uid = buffer;
        } else {
            nickname = buffer;
            mapp[uid] = nickname;
        }
        info.push_back(make_pair(command,uid));
    }
    
            
    for(auto i : info){
        string command = i.first;
        string nickname = mapp[i.second];
        
        string message = "";
        if(i.first == "Enter"){
            message += nickname;
            message += "님이 들어왔습니다.";
        } else if(i.first == "Leave"){
            message += nickname;
            message += "님이 나갔습니다.";
        } else if(i.first == "Change"){
            continue;
        }
        answer.push_back(message);
    }
    
    return answer;
}
