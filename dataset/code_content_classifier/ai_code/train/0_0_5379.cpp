#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
    int n, m, a, b;
    cin >> n >> m >> a >> b;

    int g0, x, y, z;
    cin >> g0 >> x >> y >> z;

    vector<vector<int>> heights(n, vector<int>(m));
    vector<int> g(n * m);

    g[0] = g0;
    for(int i = 1; i < n * m; i++) {
        g[i] = (g[i-1] * 1LL * x + y) % z;
    }

    int idx = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            heights[i][j] = g[idx];
            idx++;
        }
    }

    long long ans = 0;
    for(int i = 0; i < n - a + 1; i++) {
        for(int j = 0; j < m - b + 1; j++) {
            priority_queue<int, vector<int>, greater<int>> minHeap;
            for(int k = i; k < i + a; k++) {
                for(int l = j; l < j + b; l++) {
                    minHeap.push(heights[k][l]);
                }
            }
            ans += minHeap.top();
        }
    }

    cout << ans << endl;

    return 0;
}