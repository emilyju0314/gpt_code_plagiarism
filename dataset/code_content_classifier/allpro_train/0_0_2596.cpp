#include <iostream>
#include <vector>
#include <cmath>

int main() {
    int A, B, C, D, T;
    std::cin >> A >> B >> C >> D >> T;

    std::vector<int> vertices(T + 1, 0);
    vertices[0] = A;

    for (int i = 1; i <= T; i++) {
        vertices[i] = vertices[i - 1] * B - C;
        if (vertices[i] < D) {
            vertices[i] = D;
        }
    }

    double sum = 0;
    for (int i = 0; i < T; i++) {
        sum += vertices[i] + vertices[i + 1];
    }

    std::cout << std::fixed << sum / 2.0 << std::endl;

    return 0;
}