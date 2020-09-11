#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

bool MAP[2][101][101] = {0,};
bool checkFrame(int n){
    bool flag = true;
    for(int i=0; i<=n; i++){
        if(!flag) break;
        for(int j=0; j<=n; j++){
            // 기둥
            if(MAP[0][i][j]){
                // 바닥 위에 있는 경우
                if(j==0) continue;
                // 보의 한쪽 끝부분에 있는 경우
                // - 보가 양쪽에 있을 수 있는 경우
                // 왼쪽에만 있는 경우
                if(i-1>=0 && MAP[1][i-1][j]) continue;
                // 오른쪽에만 있는 경우
                if(MAP[1][i][j]) continue;
                // 기둥 위에 있는 경우
                if(j-1>=0 && MAP[0][i][j-1]) continue;
                flag = false;
                break;
            }
            // 보
            if(MAP[1][i][j]){
                // 한쪽 끝이 기둥에 있는 경우
                // 왼쪽에 기둥이 있는 경우
                if(j-1>=0 && MAP[0][i][j-1]) continue;
                // 오른쪽에 기둥이 있는 경우
                if(j-1>=0 && i+1<=n && MAP[0][i+1][j-1]) continue;
                // 양쪽 끝이 보인 경우
                if(i-1>=0 && i+1<=n){
                    if(MAP[1][i-1][j] && MAP[1][i+1][j]) continue;
                }
                flag = false;
                break;
            }
        }
    }
    return flag;
}

// 0이면 기둥
// 1이면 보 
vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
    vector<vector<int>> answer;
    
    for(int i=0; i<build_frame.size(); i++){
        int x = build_frame[i][0];
        int y = build_frame[i][1];
        int a = build_frame[i][2]; // 0 : 기둥, 1: 보
        int b = build_frame[i][3]; // 0 : 삭제, 1: 설치
        
        if(a==0){
            if(b==0){
                MAP[0][x][y] = false;
                if(!checkFrame(n)) MAP[0][x][y] = true;
            } else {
                MAP[0][x][y] = true;    
                if(!checkFrame(n)) MAP[0][x][y] = false;
            }
        } else {
            if(b==0){
                MAP[1][x][y] = false;
                if(!checkFrame(n)) MAP[1][x][y] = true;
            } else {
                MAP[1][x][y] = true;    
                if(!checkFrame(n)) MAP[1][x][y] = false;
            }
        }
    }
    
    for(int i=0; i<=n; i++){
        for(int j=0; j<=n; j++){
            if(MAP[0][i][j]){
                vector<int> tmp;
                tmp.push_back(i);
                tmp.push_back(j);
                tmp.push_back(0);
                answer.push_back(tmp);
            }
            if(MAP[1][i][j]){
                vector<int> tmp;
                tmp.push_back(i);
                tmp.push_back(j);
                tmp.push_back(1);
                answer.push_back(tmp);
            }
        } 
    }

    return answer;
}
