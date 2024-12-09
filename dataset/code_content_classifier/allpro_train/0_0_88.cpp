#include <iostream>
#include <vector>
#include <string>

int findMaxX(int n, std::vector<std::string>& matrix) {
    int maxX = n;
    
    for (int x = 2; x <= n / 4; x++) {
        bool possible = true;
        for (int i = 0; i < n; i += x) {
            for (int j = 0; j < n; j += x) {
                char element = matrix[i / x][j / x];
                for (int k = i; k < i + x; k++) {
                    for (int l = j; l < j + x; l++) {
                        if (matrix[k][l] != element) {
                            possible = false;
                            break;
                        }
                    }
                    if (!possible) break;
                }
            }
            if (!possible) break;
        }
        if (!possible) break;
        maxX = x;
    }
    
    return maxX;
}

int main() {
    int n;
    std::cin >> n;

    std::vector<std::string> matrix(n);
    for (int i = 0; i < n; i++) {
        std::cin >> matrix[i];
    }

    int maxX = findMaxX(n, matrix);
    std::cout << maxX << std::endl;

    return 0;
}