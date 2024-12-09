#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Hose {
    int weight;
    int beauty;
};

int find_friend_group(int x, vector<int>& parent) {
    if (parent[x] == x) return x;
    return parent[x] = find_friend_group(parent[x], parent);
}

void merge_friend_groups(int x, int y, vector<int>& parent) {
    int group_x = find_friend_group(x, parent);
    int group_y = find_friend_group(y, parent);
    parent[group_x] = group_y;
}

int main() {
    int n, m, w;
    cin >> n >> m >> w;

    vector<int> weights(n);
    vector<int> beauties(n);
    vector<int> parent(n);

    for (int i = 0; i < n; i++) {
        cin >> weights[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> beauties[i];
        parent[i] = i;
    }

    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        merge_friend_groups(x - 1, y - 1, parent);
    }

    vector<int> group_weights(n, 0);
    vector<int> group_beauties(n, 0);

    for (int i = 0; i < n; i++) {
        int group = find_friend_group(i, parent);
        group_weights[group] += weights[i];
        group_beauties[group] += beauties[i];
    }

    vector<vector<int>> dp(n + 1, vector<int>(w + 1, 0));

    for (int i = 0; i < n; i++) {
        for (int j = w; j >= group_weights[i]; j--) {
            dp[i + 1][j] = max(dp[i][j], dp[i][j - group_weights[i]] + group_beauties[i]);
        }
    }

    cout << dp[n][w] << endl;

    return 0;
}