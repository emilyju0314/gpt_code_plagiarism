#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;

int main() {
    int n;
    cin >> n;

    vector<string> graph(n);
    for (int i = 0; i < n; i++) {
        cin >> graph[i];
    }

    vector<int> in_deg(n), out_deg(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (graph[i][j] == '1') {
                out_deg[i]++;
                in_deg[j]++;
            }
        }
    }

    bool possible = true;
    int min_ops = 0;
    for (int i = 0; i < n; i++) {
        if (in_deg[i] + out_deg[i] < n) {
            possible = false;
            break;
        } else if (in_deg[i] == 1 && out_deg[i] == 1) {
            min_ops++;
        }
    }

    if (!possible) {
        cout << "-1\n";
    } else {
        long long ways = 1;
        for (int i = 0; i < min_ops; i++) {
            ways = (ways * 2) % MOD;
        }
        cout << min_ops << " " << ways << "\n";
    }

    return 0;
}