#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<vector<int>> graph(n, vector<int>(n));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> graph[i][j];
        }
    }

    vector<int> x(n);
    for(int i = 0; i < n; i++) {
        cin >> x[i];
    }

    vector<long long> sum_before_steps(n);
    for(int i = n-1; i >= 0; i--) {
        for(int v = 0; v < n; v++) {
            for(int u = 0; u < n; u++) {
                graph[v][u] = min(graph[v][u], graph[v][x[i]-1] + graph[x[i]-1][u]);
            }
        }

        long long sum = 0;
        for(int v = 0; v < n; v++) {
            for(int u = 0; u < n; u++) {
               sum += graph[v][u];
            }
        }

        sum_before_steps[i] = sum;
    }

    for(long long sum : sum_before_steps) {
        cout << sum << " ";
    }

    return 0;
}