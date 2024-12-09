#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }

    vector<pair<int, int>> swaps(m);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        swaps[i] = make_pair(a, b);
    }

    sort(swaps.begin(), swaps.end());

    for (int i = 0; i < m; i++) {
        int a = swaps[i].first;
        int b = swaps[i].second;

        if (p[a - 1] < p[b - 1]) {
            // Swap elements at positions a and b
            swap(p[a - 1], p[b - 1]);
        }
    }

    for (int i = 0; i < n; i++) {
        cout << p[i] << " ";
    }

    return 0;
}