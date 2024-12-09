#include <iostream>
#include <vector>
#include <algorithm>

bool isValid(int a, int b, int X, int A, int O) {
    return (a ^ b != X && (a & b) != A && (a | b) != O);
}

int main() {
    int N, X, A, O;
    std::cin >> N >> X >> A >> O;

    int upperBound = 1 << (N + 1);
    int lowerBound = 0;

    std::vector<int> result;
    bool found = false;

    for (int i = lowerBound; i < upperBound; i++) {
        for (int j = i + 1; j < upperBound; j++) {
            if (isValid(i, j, X, A, O)) {
                result.push_back(i);
                result.push_back(j);
                if (result.size() == (1 << N)) {
                    found = true;
                    break;
                }
            }
        }
        if (found) {
            break;
        }
    }

    if (found) {
        std::cout << "Yes" << std::endl;
        for (int num : result) {
            std::cout << num << " ";
        }
        std::cout << std::endl;
    } else {
        std::cout << "No" << std::endl;
    }

    return 0;
}