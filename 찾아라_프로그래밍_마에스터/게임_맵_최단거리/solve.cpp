#include<vector>
#include<iostream>
#include<algorithm>
#include<queue>

using namespace std;

int solution(vector<vector<int> > maps)
{
    int answer = 0;
    
    int col = maps.size();
    int row = maps[0].size();
    
    int visited[101][101] = {0,};
    queue<pair<int,int>> que;
    
    int dx[] = {0,0,-1,1};
    int dy[] = {-1,1,0,0};
    
    visited[0][0] = 1;
    que.push(make_pair(0,0));

    while(!que.empty()){
        queue<pair<int,int>> que2;

        while(!que.empty()){
            int x = que.front().first;
            int y = que.front().second;
            int cnt = visited[x][y];
            que.pop();
            
            for(int i=0; i<4; i++){
                int nx = x + dx[i];
                int ny = y + dy[i];
                
                if(nx<0 || ny<0 || nx>=col || ny>=row) continue;
                if(visited[nx][ny] || !maps[nx][ny]) continue;
                
                visited[nx][ny] = cnt+1;
                que2.push(make_pair(nx,ny));
            }
        }
        que = que2;
    }
    
    visited[col-1][row-1] ? answer = visited[col-1][row-1] : answer = -1;
    return answer;
}
