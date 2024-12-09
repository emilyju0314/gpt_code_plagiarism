#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

int main() {
    int n, m1, m2;
    cin >> n >> m1 >> m2;

    vector<pair<int, int>> f, g;
    for (int i = 0; i < m1; i++) {
        int a, b;
        cin >> a >> b;
        f.push_back({a, b});
    }

    for (int i = 0; i < m2; i++) {
        int a, b;
        cin >> a >> b;
        g.push_back({a, b});
    }

    unordered_set<pair<int, int>> set_f(f.begin(), f.end());
    unordered_set<pair<int, int>> set_g(g.begin(), g.end());

    if (set_f == set_g) {
        cout << "SIMILAR" << endl;
    } else {
        for (int i = 0; i < n; i++) {
            cout << "0 ";
        }
        cout << endl;
    }

    return 0;
}