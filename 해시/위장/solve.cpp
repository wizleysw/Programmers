#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    
    map<string,int> kind_map;
    
    for(auto cloth: clothes){
        kind_map[cloth[1]]++;
    }
    
    auto iter = kind_map.begin();
    for(;iter!=kind_map.end();iter++){
        answer *= iter->second+1;
    }
    
    return answer-1;
}
