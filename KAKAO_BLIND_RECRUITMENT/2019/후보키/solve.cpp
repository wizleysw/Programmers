#include <string>
#include <vector>
#include <iostream>
#include <set>

using namespace std;

int solution(vector<vector<string>> relation) {
    int answer = 0;
    
    int row = relation.size();
    int col = relation[0].size();
    
    vector<int> bit_storage;
    
    // column 정보에 대한 조합을 bitmasking으로 만듬
    for(int i=1; i<(1<<col); i++){
        set<string> sets;
        
        for(int j=0; j<row; j++){
            string str = "";
            
            // 비트가 1인 경우 str에 더해서 문자열을 만듬
            for(int k=0; k<col; k++){
                if(i&(1<<k)) str += relation[j][k];
            }
            sets.insert(str);
        }
        // set의 크기가 row와 일치하지 않는다면 중복 문자열이 존재한다는 의미
        if(sets.size() == row){
            bool flag = true;
            // 중복 문자열이 존재하지 않더라도 최소성을 만족하기 위해서는 비트 연산의 결과가 1이 나오면 안됨
            for(auto bit : bit_storage){
                // 그냥 i & bit로만 계산하였을 경우에는 1001(9) 와 0101(5)와 같이 실제로 부분집합에 포함되지 않는 경우가 존재할 수 있음
                if((i & bit) == bit){
                    flag = false;
                    break;
                }
            }
            if(flag) bit_storage.push_back(i);
        }
    }
    
    answer = bit_storage.size();
    
    return answer;
}
