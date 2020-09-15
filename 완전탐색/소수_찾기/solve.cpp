#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <set>

using namespace std;

bool is_prime(int x){
    if(x <= 1) return false;
    for(int i=2; i*i<=x; i++){
        if(x % i == 0) return false;
    }
    return true;
}

set<int> sets;
void backtracking(string cur, vector<int> &numbers, int pos){
    if(cur.size()) sets.insert(stoi(cur));
    
    if(pos == numbers.size()){
        return;
    }
    
    backtracking(cur, numbers, pos+1);
    backtracking(cur+to_string(numbers[pos]), numbers, pos+1);

}

int solution(string numbers) {
    int answer = 0;
    
    vector<int> nos;
    
    for(int i=0; i<numbers.size(); i++){
        nos.push_back(numbers[i]-'0');
    }
    sort(nos.begin(), nos.end());
    
    do {
        backtracking("", nos, 0);
    } while(next_permutation(nos.begin(), nos.end()));
    
    for(auto s : sets){
        if(is_prime(s)) answer++;
    }
    
    return answer;
}
