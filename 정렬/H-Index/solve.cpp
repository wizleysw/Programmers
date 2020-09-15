#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    
    vector<int> cited(10001, 0);
    
    for(auto citate : citations){
        for(int i=0; i<=citate; i++){
            cited[i]++;
        }
    }
    
    for(int i=0; i<cited.size(); i++){
        if(cited[i]>=i && citations.size()-cited[i]<=i){
            answer = i;
        }
    }

    return answer;
}
