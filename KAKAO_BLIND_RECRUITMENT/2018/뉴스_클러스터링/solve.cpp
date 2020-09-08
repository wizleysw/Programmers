#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(string str1, string str2) {
    int answer = 0;
        
    transform(str1.begin(), str1.end(), str1.begin(), ::tolower);
    transform(str2.begin(), str2.end(), str2.begin(), ::tolower);
    
    vector<string> v1;
    vector<string> v2;
    
    for(int i=0; i<str1.size()-1; i++){
        if(str1[i] < 'a' || str1[i] > 'z') continue;
        if(str1[i+1] < 'a' || str1[i+1] > 'z') continue;
        
        string a = "";
        a += str1[i];     
        a += str1[i+1];
        
        v1.push_back(a);
    }
    
    sort(v1.begin(), v1.end());
    
    for(int i=0; i<str2.size()-1; i++){
        if(str2[i] < 'a' || str2[i] > 'z') continue;
        if(str2[i+1] < 'a' || str2[i+1] > 'z') continue;
        
        string a = "";
        a += str2[i];     
        a += str2[i+1];
        
        v2.push_back(a);
    }
    
    sort(v2.begin(), v2.end());
    
    int p1 = 0;
    int p2 = 0;
    
    int same = 0;
    while(p1<v1.size() && p2<v2.size()){
        if(v1[p1] > v2[p2]){
            p2++;
        } else if(v1[p1] < v2[p2]){
            p1++;
        } else {
            same++;
            p1++, p2++;
        }
    }
     
    int un = v1.size() + v2.size() - same;
    
    if(!v1.size() && !v2.size()) return 65536;
    
    double result = (double) same/un;
    answer = result * 65536;
        
    return answer;
}
