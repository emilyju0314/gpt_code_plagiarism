#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> grades;
vector<vector<int>> adj_list;

bool possible(int node, int parent, int k, int grade) {
    if (grades[node] <= grade) {
        k--;
    }
    if (k == 0) {
        return true;
    }

    for (int neighbor : adj_list[node]) {
        if (neighbor != parent) {
            if (possible(neighbor, node, k, grade)) {
                return true;
            }
        }
    }

    return false;
}

int main() {
    int n, k;
    cin >> n >> k;

    grades.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> grades[i];
    }

    adj_list.resize(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }

    int low = 1, high = 1e6;
    int ans = 1;

    while (low <= high) {
        int mid = (low + high) / 2;
        if (possible(0, -1, k, mid)) {
            ans = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    cout << ans << endl;

    return 0;
}