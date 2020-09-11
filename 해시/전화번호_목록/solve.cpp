#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;

    sort(phone_book.begin(), phone_book.end());
    set<string> seet;
    
    for(auto phone: phone_book){
        string cur = "";
        for(int i=0; i<phone.size(); i++){
            cur += phone[i];
            if(seet.find(cur) != seet.end()) return false;
        }
        seet.insert(cur);
    }

    return answer;
}
