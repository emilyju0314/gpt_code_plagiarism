#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int m;
    std::cin >> m;

    std::vector<int> A(m);
    std::vector<int> B(m);

    for(int i = 0; i < m; i++) {
        std::cin >> A[i];
    }

    for(int i = 0; i < m; i++) {
        std::cin >> B[i];
    }

    std::sort(A.begin(), A.end(), std::greater<int>());

    for(int i = 0; i < m; i++) {
        std::cout << A[i] << " ";
    }

    return 0;
}