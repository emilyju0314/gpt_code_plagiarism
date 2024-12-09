#include <iostream>
#include <algorithm>

int main() {
    int t;
    std::cin >> t;

    while(t--) {
        int a, b, c;
        std::cin >> a >> b >> c;

        int total_songs = a + b + c;
        int max_songs = std::max({a, b, c});
        int min_songs = std::min({a, b, c});

        if (max_songs > total_songs - max_songs) {
            std::cout << total_songs % 2 << std::endl;
        } else {
            std::cout << (total_songs % 2) + (total_songs / 2) - max_songs << std::endl;
        }
    }

    return 0;
}