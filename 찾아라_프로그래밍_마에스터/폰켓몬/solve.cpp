#include <vector>
#include <algorithm>
#include <iostream>
#include <map>

using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;
    
    map<int, bool> mapp;
    int count = nums.size()/2;
    
    for(auto n : nums){
        mapp[n] = true;
    }
    
    mapp.size() >= count ? answer = count : answer = mapp.size();
    return answer;
}
