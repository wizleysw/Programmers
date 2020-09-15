#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    
    int total = brown + yellow;
    
    for(int i=1; i<total; i++){
        if(total%i !=0) continue;
        
        int j = total/i;
        if(i<j || j<3) continue;
    
        int border = i*2 + (j-2)*2;
        if(total-border == yellow){
            answer.push_back(i);
            answer.push_back(j);
            break;
        }
    }
    return answer;
}
