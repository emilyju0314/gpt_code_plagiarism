#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<vector<int>> adj;
vector<int> colors;
vector<vector<int>> subtree_colors;
vector<unordered_map<int, int>> color_count;
vector<int> dominating_colors_sum;

void dfs(int curr, int prev) {
    color_count[curr][colors[curr]] = 1;

    for (int neighbor : adj[curr]) {
        if (neighbor != prev) {
            dfs(neighbor, curr);

            for (auto [color, count] : color_count[neighbor]) {
                color_count[curr][color] += count;
            }
        }
    }
}

void calculate_subtree_colors(int curr, int prev) {
    for (int neighbor : adj[curr]) {
        if (neighbor != prev) {
            calculate_subtree_colors(neighbor, curr);

            for (auto [color, count] : color_count[neighbor]) {
                if (count >= color_count[curr][color]) {
                    subtree_colors[curr].push_back(color);
                }
            }
        }
    }
}

int main() {
    int n;
    cin >> n;

    adj.resize(n);
    colors.resize(n);
    subtree_colors.resize(n);
    color_count.resize(n);
    dominating_colors_sum.resize(n);

    for (int i = 0; i < n; i++) {
        cin >> colors[i];
    }

    for (int i = 0; i < n - 1; i++) {
        int x, y;
        cin >> x >> y;
        x--; y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    dfs(0, -1);
    calculate_subtree_colors(0, -1);

    for (int i = 0; i < n; i++) {
        for (int color : subtree_colors[i]) {
            dominating_colors_sum[i] += color;
        }
        cout << dominating_colors_sum[i] << " ";
    }

    return 0;
}