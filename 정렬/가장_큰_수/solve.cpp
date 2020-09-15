#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

bool compare(string &a, string &b){
    int aa = stoi(a+b);
    int bb = stoi(b+a);
    
    string aaa = to_string(aa);
    string bbb = to_string(bb);
    
    if(aaa.size() != bbb.size()) return aaa.size() > bbb.size();
    return aa>bb;
}

string solution(vector<int> numbers) {
    string answer = "";
    
    vector<string> st_numbers;
    
    for(auto number : numbers){
        st_numbers.push_back(to_string(number));
    }
    
    sort(st_numbers.begin(), st_numbers.end(), compare);

    string result = "";
    for(auto st : st_numbers){
        result += st;
    }
    
    bool flag = true;
    for(int i=0; i<result.size()-1; i++){
        if(result[i] == '0' && flag) continue;
        answer += result[i];
        flag = false;
    }
    answer += result[result.size()-1];
    
    return answer;
}
