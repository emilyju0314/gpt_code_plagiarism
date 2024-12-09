#include <iostream>
#include <vector>

int main() {
    int n, m, c;
    std::cin >> n >> m >> c;

    std::vector<int> message(n);
    for(int i = 0; i < n; i++) {
        std::cin >> message[i];
    }

    std::vector<int> key(m);
    for(int i = 0; i < m; i++) {
        std::cin >> key[i];
    }

    // Perform encryption
    for(int i = 0; i < n - m + 1; i++) {
        for(int j = 0; j < m; j++) {
            message[i + j] = (message[i + j] + key[j]) % c;
        }
    }

    // Print result
    for(int i = 0; i < n; i++) {
        std::cout << message[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}