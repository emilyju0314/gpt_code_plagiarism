#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }

    unordered_map<int, vector<int>> foes;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        foes[a].push_back(b);
        foes[b].push_back(a);
    }

    long long count = 0;
    unordered_map<int, int> last_seen;
    for (int i = 0; i < n; i++) {
        for (int j = n - 1; j >= i; j--) {
            int min_val = n + 1;
            bool has_foe = false;
            for (int k = i; k <= j; k++) {
                min_val = min(min_val, p[k]);
                for (int foe : foes[p[k]]) {
                    if (foe >= min_val && foe <= p[k]) {
                        has_foe = true;
                        break;
                    }
                }
                if (has_foe) break;
            }
            if (!has_foe) {
                count += j - i + 1;
            }
        }
    }

    cout << count << endl;

    return 0;
}