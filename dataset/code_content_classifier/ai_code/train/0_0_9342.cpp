#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <utility>

using namespace std;

vector<vector<int>> adj_list;
vector<vector<int>> companions;
vector<int> friends;
vector<int> acquaintance;

void dfs(int node, vector<int>& visited) {
    if (visited[node] == 1) {
        return;
    }
    
    visited[node] = 1;
    
    for (int neighbor : adj_list[node]) {
        dfs(neighbor, visited);
    }
}

int main() {
    int N, M;
    cin >> N >> M;
    
    adj_list.resize(N);
    
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }
    
    friends.resize(N, 0);
    acquaintance.resize(N, 0);
    
    for (int i = 0; i < N; i++) {
        vector<int> visited(N, 0);
        dfs(i, visited);
        
        for (int j = 0; j < N; j++) {
            if (visited[j] == 1) {
                friends[j] = 1;
            }
        }
    }
    
    companions.resize(N);
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i != j && friends[i] && friends[j]) {
                vector<int> visited(N, 0);
                dfs(i, visited);
                
                if (visited[j] == 1) {
                    companions[i].push_back(j);
                }
            }
        }
    }
    
    int count = 0;
    set<int> invited;
    
    for (int i = 0; i < N; i++) {
        bool include = true;
        
        for (int companion : companions[i]) {
            if (friends[companion] || friends[i]) {
                include = false;
                break;
            }
        }
        
        if (include) {
            invited.insert(i);
            count++;
        }
    }
    
    cout << count << endl;
    
    return 0;
}