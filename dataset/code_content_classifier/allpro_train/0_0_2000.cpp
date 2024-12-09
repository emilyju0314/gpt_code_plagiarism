#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> vertices(n + 1); // (parent, c_i)
    vector<vector<int>> children(n + 1);

    for (int i = 1; i <= n; i++) {
        int parent, c;
        cin >> parent >> c;
        vertices[i] = make_pair(parent, c);
        if (parent != -1) {
            children[parent].push_back(i);
        }
    }

    vector<int> deleted;
    for (int i = 1; i <= n; i++) {
        if (vertices[i].second == 1 && children[i].empty()) {
            int curr = i;
            while (curr != -1 && vertices[curr].first != -1 && vertices[vertices[curr].first].second == 1) {
                curr = vertices[curr].first;
            }
            deleted.push_back(i);
            children[vertices[curr].first].pop_back();
        }
    }

    if (deleted.empty()) {
        cout << -1 << endl;
    } else {
        for (int num : deleted) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}