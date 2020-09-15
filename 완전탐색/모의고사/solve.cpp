#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    
    int one = 0;
    int two = 0;
    int three = 0;
    
    for(int i=0; i<answers.size(); i++){
        if((i%5)+1 == answers[i]) one++;
        
        if(i%2==0 && answers[i]==2) two++;
        if(i%2){
            if(i%8 == 1 && answers[i] == 1) two++;
            else if(i%8 == 3 && answers[i] == 3) two++;
            else if(i%8 == 5 && answers[i] == 4) two++;
            else if(i%8 == 7 && answers[i] == 5) two++;
        }
        if(i%10>=0 && i%10 <= 1 && answers[i] == 3) three++;
        if(i%10 >= 2 && i%10 <= 3 && answers[i] == 1) three++;
        if(i%10 >= 4 && i%10 <= 5 && answers[i] == 2) three++;
        if(i%10 >= 6 && i%10 <= 7 && answers[i] == 4) three++;
        if(i%10 >= 8 && i%10 <= 9 && answers[i] == 5) three++;
    }
    
    priority_queue<pair<int,int>, vector<pair<int,int>>, less<>> pq;
    pq.push(make_pair(one,1));
    pq.push(make_pair(two,2));
    pq.push(make_pair(three,3));
    
    int maxv = pq.top().first;
    while(!pq.empty() && pq.top().first == maxv){
        answer.push_back(pq.top().second);
        pq.pop();
    }

    sort(answer.begin(), answer.end());
    return answer;
}
