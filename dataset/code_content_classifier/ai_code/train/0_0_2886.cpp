#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

int main() {
    long long h, n, m, k;
    cin >> h >> n >> m >> k;

    unordered_map<long long, long long> treasure;

    for (int i = 0; i < n; i++) {
        long long a, c;
        cin >> a >> c;
        treasure[a] = c;
    }

    vector<long long> steps;
    steps.push_back(k);

    for (int i = 0; i < m; i++) {
        int op;
        cin >> op;

        if (op == 1) {
            long long x;
            cin >> x;
            steps.push_back(x);
        } else if (op == 2) {
            long long x, y;
            cin >> x >> y;
            long long a = treasure[x];
            a = max(0LL, a - y);
            treasure[x] = a;
        } else if (op == 3) {
            long long max_treasure = 0;
            for (auto s : steps) {
                long long curr = 0;
                long long pos = 1;
                while (pos <= h) {
                    pos += s;
                    if (treasure.find(pos) != treasure.end()) {
                        curr = max(curr, treasure[pos]);
                    }
                }
                max_treasure = max(max_treasure, curr);
            }
            cout << max_treasure << endl;
        }
    }

    return 0;
}