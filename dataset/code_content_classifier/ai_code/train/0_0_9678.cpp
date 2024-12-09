#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int N;
    std::cin >> N;

    std::vector<int> A(N), B(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    for(int i = 0; i < N; i++) {
        std::cin >> B[i];
    }

    std::sort(B.begin(), B.end());

    bool possible = true;
    for(int i = 0; i < N; i++) {
        if(A[i] == B[i]) {
            possible = false;
            break;
        }
    }

    if(possible) {
        std::cout << "Yes" << std::endl;
        for(int i = 0; i < N; i++) {
            std::cout << B[i] << " ";
        }
        std::cout << std::endl;
    } else {
        std::cout << "No" << std::endl;
    }

    return 0;
}