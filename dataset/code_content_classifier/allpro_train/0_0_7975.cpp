#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

int main() {
    int n, k;
    cin >> n >> k;

    vector<pair<int, int>> vertices;
    for (int i = 0; i < n; ++i) {
        int val;
        cin >> val;
        vertices.push_back({val, i + 1});
    }

    vector<int> ans;
    for (int i = 0; i < n; ++i) {
        vector<int> adj_vertices;
        for (int j = 0; j < n; ++j) {
            if (i != j && gcd(vertices[i].first, vertices[j].first) > 1) {
                adj_vertices.push_back(vertices[j].second);
            }
        }
        if (adj_vertices.size() >= (n - k)) {
            ans = adj_vertices;
            break;
        }
    }

    for (int i = 0; i < k; ++i) {
        cout << ans[i] << " ";
    }
    
    return 0;
}