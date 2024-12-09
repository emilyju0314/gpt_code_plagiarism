#include <iostream>
#include <set>
#include <vector>

int main() {
    int N;
    std::cin >> N;

    std::set<std::vector<int>> surfaces;

    for (int i = 0; i < N; i++) {
        std::vector<int> surface(3);
        std::cin >> surface[0] >> surface[1] >> surface[2];
        std::sort(surface.begin(), surface.end());
        surfaces.insert(surface);
    }

    int duplicates = N - surfaces.size();

    std::cout << duplicates << std::endl;

    return 0;
}