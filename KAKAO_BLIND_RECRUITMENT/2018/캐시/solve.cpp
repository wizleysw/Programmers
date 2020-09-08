#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>

using namespace std;


int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    
    if(!cacheSize) return 5*cities.size();
    
    map<string,int> string_map;
    map<int,string> int_map;
    
    int pos = 0;
    for(string city : cities){
        transform(city.begin(), city.end(), city.begin(), ::tolower);
        pos++;
        
        if(!string_map[city]){
            answer += 5;
        }
        else {
            answer += 1;
            
            int rm = string_map[city];
            int_map.erase(rm);
            
            // 최신화
            string_map[city] = pos;
            int_map[pos] = city;
        }
        
        if(string_map.size() > cacheSize){
             auto iter = *int_map.begin();
             int_map.erase(iter.first);
             string_map.erase(iter.second);
        }
        
        string_map[city] = pos;
        int_map[pos] = city;
    }
    
    return answer;
}
