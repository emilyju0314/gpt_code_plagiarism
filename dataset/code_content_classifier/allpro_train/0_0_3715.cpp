#include <iostream>
#include <vector>

const int MOD = 10007;

int n;
std::vector<std::vector<int>> family;
std::vector<int> visited;

int dfs(int node, int parent) {
    visited[node] = 1;
    int ways = 1;
    
    for(int i = 0; i < 2; i++) {
        int partner = family[node][2 * i];
        if(partner != parent && !visited[partner]) {
            ways = (ways * (dfs(partner, node) + 1)) % MOD;
        }
    }
    
    return ways;
}

int main() {
    while (std::cin >> n && n != 0) {
        family.resize(n, std::vector<int>(4));
        visited.assign(n, 0);

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < 4; j++) {
                std::cin >> family[i][j];
            }
        }

        int total_ways = 1;
        for(int i = 0; i < n; i++) {
            if (!visited[i]) {
                total_ways = (total_ways * dfs(i, -1)) % MOD;
            }
        }

        std::cout << total_ways << std::endl;
    }

    return 0;
}