#include <iostream>
#include <string>

int main() {
    int N;
    std::cin >> N;

    std::string s, t;
    std::cin >> s >> t;

    bool found = false;
    for (int i = 1; i <= N; i++) {
        std::string first = s.substr(N - i);
        std::string last = t.substr(0, i);
        if (first == last) {
            std::cout << N + i << std::endl;
            found = true;
            break;
        }
    }

    if (!found) {
        std::cout << 2 * N << std::endl;
    }

    return 0;
}