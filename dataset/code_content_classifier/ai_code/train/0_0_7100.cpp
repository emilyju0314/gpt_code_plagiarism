#include <iostream>
#include <set>

int main() {
    int n, m;
    std::set<int> A, B;

    // Input set A
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        int num;
        std::cin >> num;
        A.insert(num);
    }

    // Input set B
    std::cin >> m;
    for (int i = 0; i < m; i++) {
        int num;
        std::cin >> num;
        B.insert(num);
    }

    // Find symmetric difference
    std::set<int> symmetricDiff;
    std::set_symmetric_difference(A.begin(), A.end(), B.begin(), B.end(), std::inserter(symmetricDiff, symmetricDiff.begin()));

    // Output the result
    for (int num : symmetricDiff) {
        std::cout << num << std::endl;
    }

    return 0;
}