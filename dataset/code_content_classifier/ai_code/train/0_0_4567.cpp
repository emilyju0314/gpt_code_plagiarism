#include <iostream>
#include <vector>

#define MOD 1000000007

using namespace std;

vector<int> edges[5001];
int dp[5001][5001];
int N;

int count_ways(int u, int parent, int is_parent_edge) {
    if (dp[u][is_parent_edge] != -1) {
        return dp[u][is_parent_edge];
    }

    int num_ways = 1, sum_of_none = 0;
    // For each child of vertex u
    for (int v : edges[u]) {
        if (v != parent) {
            sum_of_none += count_ways(v, u, 0);
            sum_of_none %= MOD;
        }
    }

    // If the current edge is included in a ribbon
    if (is_parent_edge) {
        num_ways = sum_of_none;
    } else {
        int sum_of_one = 0;
        for (int v : edges[u]) {
            if (v != parent) {
                int num_children = count_ways(v, u, 0);
                int num_grandchildren = (sum_of_none - num_children + MOD) % MOD;
                sum_of_one = (sum_of_one + (long long)num_children * num_grandchildren) % MOD;
            }
        }
        num_ways = (sum_of_one + sum_of_none) % MOD;
    }

    dp[u][is_parent_edge] = num_ways;
    return num_ways;
}

int main() {
    cin >> N;
    for (int i = 0; i < N-1; i++) {
        int x, y;
        cin >> x >> y;
        edges[x].push_back(y);
        edges[y].push_back(x);
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 0; j <= N; j++) {
            dp[i][j] = -1;
        }
    }

    int result = count_ways(1, 0, 1);
    cout << result << endl;

    return 0;
}