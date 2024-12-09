#include <iostream>
#include <vector>
#define MOD 1000000007

using namespace std;

int dfs(int node, vector<int>& a, vector<bool>& visited, vector<bool>& onStack) {
    visited[node] = true;
    onStack[node] = true;
    
    int next = a[node] - 1;
    int result = 1;
    
    if (!visited[next]) {
        result += dfs(next, a, visited, onStack);
    } else if (onStack[next]) {
        result = 0;
    }
    
    onStack[node] = false;
    
    return result;
}

int main() {
    int n;
    cin >> n;
    
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    vector<bool> visited(n, false);
    vector<bool> onStack(n, false);
    
    long long total = 1;
    
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            int result = dfs(i, a, visited, onStack);
            total = (total * 2) % MOD;
            total = (total - result + MOD) % MOD;
        }
    }
    
    cout << total << endl;
    
    return 0;
}