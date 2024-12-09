#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> f(n), w(n), si(n), mi(n);
    for (int i = 0; i < n; i++) {
        cin >> f[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> w[i];
    }

    vector<long long> sum(n, 0), min_weight(n, INT_MAX);
    vector<bool> visited(n, false);

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            vector<int> path;
            int current = i;
            while (!visited[current]) {
                visited[current] = true;
                path.push_back(current);
                current = f[current];
            }

            int cycle_len = path.size();
            int start_cycle = path[0];

            for (int j = 0; j < cycle_len; j++) {
                sum[path[j]] = sum[start_cycle];
                min_weight[path[j]] = min(min_weight[start_cycle], w[path[j]]);
            }

            for (int j = 0; j < cycle_len; j++) {
                si[path[j]] = (k / cycle_len) * sum[path[j]];
                mi[path[j]] = min_weight[path[j]];

                int remainder = k % cycle_len;
                for (int l = 0; l < remainder; l++) {
                    si[path[j]] += w[path[(j + l) % cycle_len]];
                    mi[path[j]] = min(mi[path[j]], w[path[(j + l) % cycle_len]]);
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        cout << si[i] << " " << mi[i] << endl;
    }

    return 0;
}