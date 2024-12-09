#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int N, L;
    std::cin >> N >> L;

    std::vector<std::string> strings(N);
    for (int i = 0; i < N; i++) {
        std::cin >> strings[i];
    }

    std::sort(strings.begin(), strings.end());

    std::string result = "";
    for (int i = 0; i < N; i++) {
        result += strings[i];
    }

    std::cout << result << std::endl;

    return 0;
}