#include <iostream>
#include <vector>

int main() {
    int n, k;
    std::cin >> n;

    // Store the initial shortest distances
    std::vector<std::vector<int>> dist(n, std::vector<int>(n));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            std::cin >> dist[i][j];
        }
    }

    std::cin >> k;

    // Calculate the shortest distance sum after adding each new road
    int sum = 0;
    for(int i = 0; i < k; i++) {
        int a, b, c;
        std::cin >> a >> b >> c;

        for(int j = 0; j < n; j++) {
            for(int l = 0; l < n; l++) {
                dist[j][l] = std::min(dist[j][l], dist[j][a-1] + c + dist[b-1][l]);
                dist[j][l] = std::min(dist[j][l], dist[j][b-1] + c + dist[a-1][l]);
                sum += dist[j][l];
            }
        }

        std::cout << sum << " ";
    }

    return 0;
}