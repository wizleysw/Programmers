#include <algorithm>
#include <iostream>
#include <queue>
#include <tuple>
#include <vector>

using namespace std;

int solution(int n, int a, int b)
{
    queue<tuple<int,int,int>> que;
    if(a>b) swap(a,b);
        
    for(int i=1; i<=n; i=i+2){
        que.push((tuple<int,int,int>{i, i+1, 1}));
        if(a==i && b==i+1) return 1;
    }
    
    while(que.size()>=2){
        auto f1 = que.front();
        que.pop();
        
        if(get<0>(f1) <= a && get<1>(f1) >= b) return get<2>(f1);
        
        auto f2 = que.front();
        que.pop();
        
        if(get<0>(f2) <= a && get<1>(f2) >= b) return get<2>(f2);

        que.push((tuple<int,int,int>{get<0>(f1), get<1>(f2), get<2>(f2)+1}));
        
    }
    return get<2>(que.front());
}
