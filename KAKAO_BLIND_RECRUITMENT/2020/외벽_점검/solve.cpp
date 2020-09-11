#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
int solution(int n, vector<int> weak, vector<int> dist) {
    int answer = 987654321;
    
    for(int i=0; i<weak.size(); i++){
        vector<int> permute;
        for(int j=0; j<weak.size(); j++){
            if(i+j>=weak.size()){
                permute.push_back(weak[i+j-weak.size()]+n);
            } else {
                permute.push_back(weak[i+j]);
            }
        }
    
        sort(dist.begin(), dist.end());
        do{
            vector<bool> visited(n, false);
            for(int k=0; k<dist.size(); k++){
                int cur = -1;
                for(int p=0; p<permute.size(); p++){
                    if(permute[p]>=n){
                        if(!visited[permute[p]-n]){
                            cur = p;
                            break;
                        }
                    }
                    else {
                        if(!visited[permute[p]]){
                            cur = p;
                            break;
                        }
                    }
                }
                if(cur != -1){
                    for(int c=permute[cur]; c<=permute[cur]+dist[k]; c++){
                        if(c>=n){
                            visited[c-n] = true;
                        }else {
                            visited[c] = true;
                        }
                    }
                }                
                bool flag = true;
                for(int xx=0; xx<weak.size(); xx++){
                    if(!visited[weak[xx]]) flag = false;
                }
                if(flag){
                    answer = min(answer, k+1);
                }
            }
        }while(next_permutation(dist.begin(), dist.end()));
    }
    if(answer == 987654321) answer = -1;
    return answer;
}
