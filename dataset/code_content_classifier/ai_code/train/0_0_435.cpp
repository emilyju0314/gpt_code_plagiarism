#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> p(n+1);
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
    }

    vector<pair<int, int>> swaps;
    int m = 0;

    for (int i = 1; i <= n; i++) {
        if (p[i] != i) {
            int j = i + 1;
            while (p[j] != i) {
                j++;
            }
            if (j-i >= n/2) {
                swap(p[i], p[j]);
                swaps.push_back({i, j});
                m++;
            } else {
                int k = i + n/2;
                swap(p[i], p[k]);
                swaps.push_back({i, k});
                swap(p[j], p[k]);
                swaps.push_back({j, k});
                swap(p[i], p[k]);
                swaps.push_back({i, k});
                m += 3;
            }
        }
    }

    cout << m << endl;
    for (auto s : swaps) {
        cout << s.first << " " << s.second << endl;
    }

    return 0;
}