#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    unordered_map<int, unordered_set<int>> colors;
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        if (colors.find(c) == colors.end()) {
            colors[c] = unordered_set<int>();
        }
        colors[c].insert(a);
        colors[c].insert(b);
    }

    int q;
    cin >> q;

    for (int i = 0; i < q; i++) {
        int u, v;
        cin >> u >> v;

        unordered_set<int> commonColors;
        for (auto& entry : colors) {
            if (entry.second.count(u) && entry.second.count(v)) {
                commonColors.insert(entry.first);
            }
        }

        cout << commonColors.size() << endl;
    }

    return 0;
}