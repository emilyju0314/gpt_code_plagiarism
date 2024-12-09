#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int N;
    std::cin >> N;

    std::vector<std::vector<int>> graph(N, std::vector<int>(N));

    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < N; ++j) {
            std::cin >> graph[i][j];
        }
    }

    int max_dist = 0;

    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < N; ++j) {
            for(int k = 0; k < N; ++k) {
                if(i != j && j != k && i != k) {
                    int dist = graph[i][j] + graph[j][k];
                    max_dist = std::max(max_dist, dist);
                }
            }
        }
    }

    std::cout << max_dist << std::endl;

    return 0;
}