#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int q;
    cin >> q;

    int n = 4;
    vector<pair<int, int>> treeEdges = {{1, 2}, {1, 3}, {1, 4}};
    vector<int> diameters = {2, 2, 2, 2};

    for (int i = 0; i < q; i++) {
        int v;
        cin >> v;

        n += 2;
        treeEdges.push_back({v, n - 1});
        treeEdges.push_back({v, n});

        for (auto edge : treeEdges) {
            diameters[edge.first - 1] = max(diameters[edge.first - 1], max(diameters[edge.second - 1] + 1, diameters[n - 1] + diameters[n]));
        }

        cout << *max_element(diameters.begin(), diameters.end()) << endl;
    }

    return 0;
}