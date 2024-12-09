#include <iostream>
#include <vector>

int main() {
    int n, a, b;
    std::cin >> n >> a >> b;

    std::vector<int> tokens(n);
    for (int i = 0; i < n; i++) {
        std::cin >> tokens[i];
    }

    for (int i = 0; i < n; i++) {
        int saved_tokens = (tokens[i] * a) % b / a;
        std::cout << saved_tokens << " ";
    }

    return 0;
}