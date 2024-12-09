#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, k;
vector<int> adj[1501];

bool query(int a, int b, int c) {
    cout << "? " << a << " " << b << " " << c << endl;
    string response;
    cin >> response;
    return response == "Yes";
}

int main() {
    cin >> n >> k;

    for (int i = 2; i <= n; i++) {
        adj[(i - 2) / k + 1].push_back(i);
    }

    vector<int> leaves;
    for (int i = 1; i <= n; i++) {
        if (adj[i].empty()) {
            leaves.push_back(i);
        }
    }

    int root = 1;
    for (int i = 2; i <= n; i++) {
        bool is_root = true;
        for (int leaf : leaves) {
            if (!query(root, i, leaf)) {
                is_root = false;
                break;
            }
        }
        if (is_root) {
            root = i;
        }
    }

    cout << "! " << root << endl;

    return 0;
}