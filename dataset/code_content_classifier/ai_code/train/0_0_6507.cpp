#include <iostream>
#include <vector>

bool isSymmetric(std::vector<std::string> &matrix) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (matrix[i][j] != matrix[2 - i][2 - j]) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    std::vector<std::string> matrix(3);
    
    for (int i = 0; i < 3; i++) {
        std::cin >> matrix[i];
    }

    if (isSymmetric(matrix)) {
        std::cout << "YES" << std::endl;
    } else {
        std::cout << "NO" << std::endl;
    }

    return 0;
}