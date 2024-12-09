#include <iostream>
#include <vector>

int main() {
    int N, M;
    std::cin >> N >> M;

    std::vector<int> buttons(M);
    for (int i = 0; i < M; i++) {
        std::cin >> buttons[i];
    }

    int lcm = 1;
    for (int i = 0; i < M; i++) {
        int temp = (buttons[i] / std::__gcd(lcm, buttons[i]));
        lcm = temp * lcm;
    }

    std::cout << ((lcm <= N) ? "Yes" : "No") << std::endl;

    return 0;
}