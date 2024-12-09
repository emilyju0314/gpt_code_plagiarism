#include <iostream>
#include <vector>

int main() {
    int N, L, T;
    std::cin >> N >> L >> T;

    std::vector<std::pair<int, int>> ants(N); // pair consists of X coordinate and initial direction
    for (int i = 0; i < N; i++) {
        std::cin >> ants[i].first >> ants[i].second;
    }

    for (int i = 0; i < N; i++) {
        int distance = T % L; // calculate the distance ant i travels after T seconds
        if (ants[i].second == 1) {
            ants[i].first = (ants[i].first + distance) % L;
        } else {
            ants[i].first = (ants[i].first - distance + L) % L;
        }
        std::cout << ants[i].first << std::endl;
    }

    return 0;
}