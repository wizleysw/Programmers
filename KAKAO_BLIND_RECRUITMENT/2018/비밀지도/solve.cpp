#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    
    vector<int> combined;
    for(int i=0; i<n; i++){
        combined.push_back(arr1[i] | arr2[i]);
    }
    
    for(int i=0; i<combined.size(); i++){
        string result = "";
        for(int bit=n-1; bit>=0; bit--){
            if(combined[i] & 1<<bit) result += "#";
            else result += " ";
        }
        answer.push_back(result);
    }
    return answer;
}
