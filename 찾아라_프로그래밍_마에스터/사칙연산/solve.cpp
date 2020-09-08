#include <algorithm>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int solution(vector<string> arr)
{
    int answer = 0;
    int dpMax[202][202] = {0,};
    int dpMin[202][202] = {0,};
    
    for(int i=0; i<202; i++){
        for(int j=0; j<202; j++){
            dpMax[i][j] = -987654321;
            dpMin[i][j] = 987654321;
        }
    }
    
    int no_cnt = arr.size()/2+1;
    for(int i=0; i<no_cnt; i++){
        dpMax[i][i] = stoi(arr[i*2]);
        dpMin[i][i] = stoi(arr[i*2]);
    }
    
    for(int exp_cnt=1; exp_cnt<no_cnt; exp_cnt++){
        
        for(int left=0; left<no_cnt-exp_cnt; left++){
            int right = left+exp_cnt;
            for(int mid=left; mid<right; mid++){
                string exp = arr[2*mid+1];
                
                if(exp == "+"){
                    dpMax[left][right] = max(dpMax[left][right], dpMax[left][mid]+dpMax[mid+1][right]);
                    dpMin[left][right] = min(dpMin[left][right], dpMin[left][mid]+dpMin[mid+1][right]);
                } else if(exp == "-"){
                    dpMax[left][right] = max(dpMax[left][right], dpMax[left][mid]-dpMin[mid+1][right]);
                    dpMin[left][right] = min(dpMin[left][right], dpMin[left][mid]-dpMax[mid+1][right]);
                }
            }
        }   
    }
    
    answer = dpMax[0][no_cnt-1];
    return answer;
}
