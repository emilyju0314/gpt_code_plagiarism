#include <iostream>
#include <vector>
#include <cmath>

bool is_prime(int num) {
    if(num < 2) return false;
    for(int i = 2; i <= sqrt(num); i++) {
        if(num % i == 0) return false;
    }
    return true;
}

int main() {
    int n, m;
    std::cin >> n >> m;

    std::vector<std::vector<int>> matrix(n, std::vector<int>(m));

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            std::cin >> matrix[i][j];
        }
    }

    std::vector<int> rows(n, 0);
    std::vector<int> cols(m, 0);

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(!is_prime(matrix[i][j])) {
                int diff = 0;
                while(!is_prime(matrix[i][j] + diff)) {
                    diff++;
                }
                rows[i] = std::max(rows[i], diff);
                cols[j] = std::max(cols[j], diff);
            }
        }
    }

    int min_moves = 0;
    for(int i = 0; i < n; i++) {
        min_moves += rows[i];
    }

    for(int j = 0; j < m; j++) {
        min_moves += cols[j];
    }

    std::cout << min_moves << std::endl;

    return 0;
}