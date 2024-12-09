#include <iostream>
#include <vector>
#include <map>
#include <climits>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<map<int, int>> graph(n+1); // Using map to store channel duration for each planet
    
    for (int i = 0; i < n; i++) {
        int a, b, t;
        cin >> a >> b >> t;
        graph[a][b] = t;
        graph[b][a] = t;
    }
    
    vector<int> res(n+1, INT_MAX);
    for (int i = 1; i <= n; i++) {
        int total_time = 0;
        for (auto& itr : graph[i]) {
            total_time += itr.second;
            for (auto& itr2 : graph[itr.first]) {
                if (itr2.first != i) {
                    total_time += itr2.second;
                }
            }
            res[i] = min(res[i], total_time);
            total_time = 0;
        }
    }
    
    for (int i = 1; i <= n; i++) {
        cout << res[i] << " ";
    }
    
    return 0;
}