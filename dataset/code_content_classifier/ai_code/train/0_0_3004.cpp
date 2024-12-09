#include <iostream>
#include <string>
#include <algorithm>

int main() {
    int N;
    std::cin >> N;
    std::string sequence;
    std::cin >> sequence;

    int x[N][N];

    for (int j = 0; j < N; j++) {
        x[0][j] = sequence[j] - '0'; // converting char to integer
    }

    for (int i = 1; i < N; i++) {
        for (int j = 0; j < N - i; j++) {
            x[i][j] = abs(x[i-1][j] - x[i-1][j+1]);
        }
    }

    std::cout << x[N-1][0] << std::endl;

    return 0;
}