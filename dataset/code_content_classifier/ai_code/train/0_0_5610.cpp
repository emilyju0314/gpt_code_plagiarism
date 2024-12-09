#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    
    string s;
    cin >> s;
    
    vector<vector<int>> adj(N);
    vector<int> degree(N, 0);
    
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
        degree[a]++;
        degree[b]++;
    }
    
    bool possible = true;
    
    for (int i = 0; i < N; i++) {
        if (s[i] == 'A' && degree[i] % 2 != 0) {
            possible = false;
            break;
        }
    }
    
    if (possible) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    
    return 0;
}