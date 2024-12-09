#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> p(n + 1);
    for (int i = 1; i <= n; i++) {
        std::cin >> p[i];
    }

    for (int a = 1; a <= n; a++) {
        std::vector<bool> visited(n + 1, false);
        int current = a, count = 0;
        while (!visited[current]) {
            visited[current] = true;
            current = p[current];
            count++;
        }
        if (count == 2) {
            std::cout << current << " ";
        } else {
            std::cout << "0 ";
        }
    }

    return 0;
}