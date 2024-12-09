#include <iostream>
#include <vector>
#include <unordered_map>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> A(n);
    std::vector<int> B(n);

    for (int i = 0; i < n; i++) {
        std::cin >> A[i];
    }

    for (int i = 0; i < n; i++) {
        std::cin >> B[i];
    }

    // Create a map to store the prefix sums for A
    std::unordered_map<int, std::vector<int>> prefixSumsA;
    int sumA = 0;
    for (int i = 0; i < n; i++) {
        sumA += A[i];
        prefixSumsA[sumA].push_back(i);
    }

    // Calculate the prefix sum for B simultaneously and check for a match
    int sumB = 0;
    bool found = false;
    int idxA, idxB;
    for (int i = 0; i < n; i++) {
        sumB += B[i];
        if (prefixSumsA.find(sumB) != prefixSumsA.end()) {
            found = true;
            idxA = prefixSumsA[sumB][0];
            idxB = i;
            break;
        }
    }

    // Output the results
    if (found) {
        std::cout << "2\n";
        std::cout << idxA + 1 << " " << idxB + 1 << "\n";
        std::cout << "2\n";
        std::cout << "1 " << idxB + 1 << "\n";
    } else {
        std::cout << "-1\n";
    }

    return 0;
}