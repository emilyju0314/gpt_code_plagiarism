#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int w, n;
    std::cin >> w >> n;

    std::vector<int> lines(w);
    for (int i = 0; i < w; i++) {
        lines[i] = i + 1;
    }

    for (int i = 0; i < n; i++) {
        int a, b;
        char comma;
        std::cin >> a >> comma >> b;
        std::swap(lines[a - 1], lines[b - 1]);
    }

    for (int i = 0; i < w; i++) {
        std::cout << lines[i] << std::endl;
    }

    return 0;
}