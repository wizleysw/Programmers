#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
char MAP[31][31] = {0,};
bool ERASE[31][31] = {0,};

bool checkErase(int m, int n, int x, int y){
    if(x+1>=m || y+1>=n) return false;
    
    if(MAP[x][y] == MAP[x][y+1] && MAP[x+1][y] == MAP[x+1][y+1] && MAP[x][y] == MAP[x+1][y]){
        if(MAP[x][y] != 'x') return true;
    }
    return false;
}

void eraseBlock(int m, int n){
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(ERASE[i][j]){
                MAP[i][j] = 'x';
                MAP[i][j+1] = 'x';
                MAP[i+1][j] = 'x';
                MAP[i+1][j+1] = 'x';
            }
            ERASE[i][j] = false;
        }
    }
}

void shiftBlock(int m, int n){
    for(int i=0; i<n; i++){
        vector<char> tmp;
        for(int j=0; j<m; j++){
            if(MAP[j][i] != 'x'){
                tmp.push_back(MAP[j][i]);
            }
        }
        
        while(tmp.size() < m){
            tmp.insert(tmp.begin(), 'x');
        }
        
        for(int k=0; k<tmp.size(); k++){
            MAP[k][i] = tmp[k];
        }   
    }    
}

void printBlock(int m, int n){
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            cout << MAP[i][j];
        }
        cout << "\n";
    }
}

int countX(int m, int n){
    int cnt = 0;
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(MAP[i][j] == 'x') cnt++;
        }
    }
    return cnt;
}

int solution(int m, int n, vector<string> board) {
    int answer = 0;
    
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            MAP[i][j] = board[i][j];       
        }
    }
    
    while(true){
        int erase_cnt = 0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(checkErase(m,n,i,j)){
                    ERASE[i][j] = true;
                    erase_cnt++;
                }
            }
        }
        
        if(!erase_cnt) break;
        
        eraseBlock(m,n);
        answer = countX(m,n);
        shiftBlock(m,n);
    }

    return answer;
}
