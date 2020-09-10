#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

void printBoard(vector<vector<int>> &b){
    for(int i=0; i<b.size(); i++){
        for(int j=0; j<b.size(); j++){
            cout << b[i][j];
        }
        cout << "\n";
    }
    cout << "==============\n";
}

bool checkBoard(vector<vector<int>> &board, vector<vector<int>> &key, vector<pair<int,int>> &hole){
    for(int i=0; i<board.size(); i++){
        for(int j=0; j<board.size(); j++){
            bool flag = true;
            
            auto board2 = board;
            for(int x=0; x<key.size(); x++){
                for(int y=0; y<key.size(); y++){
                    int nx = i+x;
                    int ny = j+y;
                    
                    if(nx<0 || ny<0 || nx>=board2.size() || ny>=board2.size()) continue;
                    
                    if(board2[nx][ny] == 1 && key[x][y] == 1){
                        flag = false;
                        break;
                    }
                    
                    board2[nx][ny] = max(board2[nx][ny], key[x][y]);
                }
                if(!flag) break;
            }

            if(flag){
                bool all_satisfied = true;
                for(int h=0; h<hole.size(); h++){
                    int xx = hole[h].first;
                    int yy = hole[h].second;
                    
                    if(!board2[xx][yy]){
                        all_satisfied = false;
                        break;
                    }
                }

                if(all_satisfied){
                    return true;
                }
            }
        }
        
    }
    return false;
}

void swap(vector<vector<int>> &key){
    vector<vector<int>> rotated = key;
    
    int size = key.size();
    
    int left = 0;
    int right = 0;
    
    for(int i=0; i<size; i++){
        for(int j=size-1; j>=0; j--){
            rotated[left][right] = key[j][i];
            right++;
            if(right == size){
                left++;
                right = 0;
            }  
        }
    }
    key = rotated;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    bool answer = false;
    vector<vector<int>> board(lock.size()*3);
    for(int i=0; i<board.size(); i++){
        board[i].resize(lock.size()*3);   
    }
    
    vector<pair<int,int>> hole;
    for(int i=0; i<lock.size(); i++){
        for(int j=0; j<lock.size(); j++){
            board[lock.size()+i][lock.size()+j] = lock[i][j];
            if(lock[i][j] == 0) hole.push_back(make_pair(lock.size()+i, lock.size()+j));
        }
    }
    
    for(int i=0; i<4; i++){
        swap(key);
        if(checkBoard(board, key, hole)){
            answer = true;
            break;
        }
    }

    return answer;
}
