#include <string>
#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Node{
    Node* left;
    Node* right;
    int no;
    int pos;
    int level;
    
    Node(int num, int p, int lev){
        no = num;
        pos = p;
        level = lev;
        left = NULL;
        right = NULL;
    }
};

vector<int> pre;
vector<int> post;
vector<Node*> nodes;
Node* root = NULL;

bool compare(pair<int,pair<int,int>> &a, pair<int,pair<int,int>> &b){
    if(a.first != b.first) return a.first > b.first;
    return a.second.first < b.second.first;
}

void preOrder(Node* cur){
    if(cur == NULL) return;
    pre.push_back(cur->no);
    preOrder(cur->left);
    preOrder(cur->right);
}

void postOrder(Node* cur){
    if(cur == NULL) return;
    postOrder(cur->left);
    postOrder(cur->right);
    post.push_back(cur->no);
}

void insertTree(Node *root, int position, int index){
    Node *cur = root;

    while(cur != NULL){
        // LEFT
        if(position < cur->pos){
            if(cur->left == NULL){
                cur->left = nodes[index];
                break;
            } 
            cur = cur->left;
        }

        // RIGHT
        else if(position > cur->pos){
            if(cur->right == NULL){
                cur->right = nodes[index];
                break;
            }
            cur = cur->right;
        }
    }
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    vector<vector<int>> answer;
    vector<pair<int,pair<int,int>>> nodev;
    
    nodes.resize(nodeinfo.size()+1);
    
    for(int i=0; i<nodeinfo.size(); i++){
        int pos = nodeinfo[i][0];
        int level = nodeinfo[i][1];
        
        nodes[i+1] = new Node(i+1, pos, level);
        nodev.push_back(make_pair(level, make_pair(pos, i+1)));
    }
    
    sort(nodev.begin(), nodev.end(), compare);
    
    root = nodes[(nodev[0].second).second];
    for(int i=1; i<nodev.size(); i++){
        int level = nodev[i].first;
        int pos = nodev[i].second.first;
        int no = nodev[i].second.second;
        insertTree(root, pos, no);
    }
    
    preOrder(root);
    postOrder(root);
    
    answer.push_back(pre);
    answer.push_back(post);
    
    return answer;
}
