#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<vector<int>> tree(n);
        for (int i = 0; i < n - 1; i++) {
            int a, b;
            cin >> a >> b;
            a--; b--;
            tree[a].push_back(b);
            tree[b].push_back(a);
        }

        vector<int> degree(n);
        for (int i = 0; i < n; i++) {
            degree[i] = tree[i].size();
        }

        vector<pair<int, int>> edges;
        vector<int> leaves;
        for (int i = 0; i < n; i++) {
            if (degree[i] == 1 || degree[i] == 0) {
                leaves.push_back(i);
            }
        }

        int k = n - 1;
        if (leaves.size() % 2 == 1) {
            k++;
            leaves.push_back(leaves[0]);
        }

        cout << k << endl;
        for (int i = 0; i < leaves.size(); i += 2) {
            cout << leaves[i % n] + 1 << " " << leaves[(i + 1) % n] + 1 << " " << leaves[(i + n/2) % n] + 1<< " " << leaves[(i + n/2 + 1) % n] + 1 << endl;
        }
    }

    return 0;
}