#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <string.h>
#include <map>

using namespace std;

struct TRIE {
    TRIE *children[27];
    bool terminal = false;
    
    TRIE() : terminal(false){
        memset(children, 0, sizeof(children));
    }
    
    ~TRIE(){
        for(int i=0; i<27; i++){
            if(children[i]) delete children[i];
        }
    }
    
    void insert(string &key, int pos){
        if(key[pos] == '\0'){
            terminal = true;
        }
        else {
            int next = key[pos] - 'a';
            
            if(children[next] == NULL){
                children[next] = new TRIE();
            }
            children[next]->insert(key, pos+1);
        }
    }
    
    int find(string &key, int pos){
        if(key[pos] == '\0' || pos == key.size()){
            return terminal;
        }
        
        int next = key[pos] - 'a';
        
        if(key[pos] == '?'){
            int cnt = 0;
            for(int i=0; i<27; i++){
                if(children[i] == NULL) continue;
                cnt += children[i]->find(key, pos+1);
            }
            return cnt;
        } else {
            if(children[next] == NULL) return 0;
            return children[next]->find(key, pos+1);
        }
    }
};
TRIE *root[10001];
TRIE *reverse_root[10001];
vector<int> solution(vector<string> words, vector<string> queries) {
    vector<int> answer;
    
    for(auto word : words){
        int size = word.size();
        if(root[size] == NULL) root[size] = new TRIE(); 
        root[size]->insert(word, 0);
        
        string word2 = word;
        reverse(word2.begin(), word2.end());

        if(reverse_root[size] == NULL) reverse_root[size] = new TRIE();
        reverse_root[size]->insert(word2, 0);
    }
    
    map<string,int> mapp;
    map<string,int> rv_mapp;
    for(auto query: queries){
        int qs = query.size();
        if(query[0] == '?'){
            reverse(query.begin(), query.end());
            
            if(rv_mapp.find(query) != rv_mapp.end()){
                answer.push_back(rv_mapp[query]);
            }
            else {
                if(reverse_root[qs] == NULL){
                    answer.push_back(0);
                } else {
                    int result = reverse_root[qs]->find(query, 0);
                    rv_mapp[query] = result;
                    answer.push_back(result);
                }
            }
        } else {
            
            if(mapp.find(query) != mapp.end()){
                answer.push_back(mapp[query]);
            }
            else {
                if(root[qs] == NULL){
                    answer.push_back(0);
                } else {
                    int result = root[qs]->find(query, 0);
                    mapp[query] = result;
                    answer.push_back(result);
                }
            }
        }
    }
    
    return answer;
}
