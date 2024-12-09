#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, d, k;
    cin >> n >> d >> k;

    if (d >= n) {
        cout << "NO" << endl;
    } else {
        vector<pair<int, int>> tree;
        int current_vertex = 2;
        for (int i = 2; i <= d + 1; i++) {
            tree.push_back({1, i});
            current_vertex = i + 1;
        }

        for (int i = 2; i <= d + 1; i++) {
            int remaining_degree = k - 1;
            for (int j = current_vertex; j <= n && remaining_degree > 0; j++) {
                tree.push_back({i, j});
                remaining_degree--;
                current_vertex++;
            }
        }

        if (current_vertex <= n) {
            cout << "YES" << endl;
            for (auto edge : tree) {
                cout << edge.first << " " << edge.second << endl;
            }
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}