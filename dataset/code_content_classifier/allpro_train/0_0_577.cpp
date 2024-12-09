#include <iostream>
#include <vector>

int main() {
    int N, M;
    std::cin >> N >> M;

    std::vector<int> digits(N, -1);

    for(int i = 0; i < M; i++) {
        int s, c;
        std::cin >> s >> c;
        if(s > N || (s == 1 && c == 0 && N > 1)) {
            std::cout << -1 << std::endl;
            return 0;
        }

        digits[s - 1] = c;
    }

    if(N > 1 && digits[0] == 0) {
        std::cout << -1 << std::endl;
        return 0;
    }

    for(int i = 0; i < N; i++) {
        if(digits[i] == -1) {
            if(i == 0 && N > 1) {
                digits[i] = 1;
            } else {
                digits[i] = 0;
            }
        }
    }

    for(int i = 0; i < N; i++) {
        std::cout << digits[i];
    }
    std::cout << std::endl;

    return 0;
}