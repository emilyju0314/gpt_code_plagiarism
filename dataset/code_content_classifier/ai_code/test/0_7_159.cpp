#include <iostream>
#include <vector>

bool isPerfectSquare(long long n) {
    long long sqrtN = sqrt(n);
    return sqrtN * sqrtN == n;
}

int main() {
    int n;
    std::cin >> n;

    std::vector<int> subset;

    for (int i = 1; i <= n; i++) {
        if (isPerfectSquare(i)) {
            subset.push_back(i);
        }
    }

    std::cout << subset.size() << std::endl;
    for (int i = 0; i < subset.size(); i++) {
        std::cout << subset[i] << " ";
    }

    return 0;
}