#include <iostream>
#include <unordered_map>

int main() {
    int n;
    std::cin >> n;

    std::unordered_map<int, int> diagonal1, diagonal2;
    long long count = 0;

    for (int i = 0; i < n; i++) {
        int x, y;
        std::cin >> x >> y;
        count += (long long)diagonal1[x+y];
        count += (long long)diagonal2[x-y];
        diagonal1[x+y]++;
        diagonal2[x-y]++;
    }

    std::cout << count << std::endl;

    return 0;
}