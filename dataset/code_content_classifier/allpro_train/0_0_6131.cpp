#include <bits/stdc++.h>
using namespace std;

int findInconsistentLine(int N, int M, int K, vector<pair<int, pair<int, int>>> records) {
    vector<int> parent(N + 1);
    
    for(int i = 1; i <= N; i++) {
        parent[i] = i;
    }
    
    for(int i = 0; i < K; i++) {
        int type = records[i].first;
        int a = records[i].second.first;
        int b = records[i].second.second;
        
        if(type == 1) {
            if(parent[a] == parent[b]) {
                return i + 1;
            }
            
            for(int j = 1; j <= N; j++) {
                if(parent[j] == parent[b]) {
                    parent[j] = parent[a];
                }
            }
        }
        else {
            if(parent[a] == parent[b]) {
                return i + 1;
            }
            parent[b] = parent[a];
        }
    }
    
    return 0;
}

int main() {
    int N, M, K;
    cin >> N >> M >> K;
    
    vector<pair<int, pair<int, int>>> records;
    
    for(int i = 0; i < K; i++) {
        int type, a, b;
        cin >> type >> a >> b;
        
        records.push_back({type, {a, b}});
    }
    
    int inconsistentLine = findInconsistentLine(N, M, K, records);
    
    cout << inconsistentLine << endl;
    
    return 0;
}