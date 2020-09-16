#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <set>

using namespace std;

string solution(string number, int k) { 
    string answer = "";

    int idx = -1;
    for(int i=0; i<number.size()-k; i++){
        char ch = '0';
        
        for(int j=idx+1; j<=i+k; j++){
    
            if(number[j] > ch){
                idx = j;
                ch = number[j];
            }
        }
        
        answer += ch;
    }
    
    return answer;
}
