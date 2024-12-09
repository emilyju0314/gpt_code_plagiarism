#include <iostream>

int main() {
    int n, k;
    std::cin >> n >> k;
    
    int table[n][n];
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(i == j) {
                table[i][j] = k - (n-1);
            } else {
                table[i][j] = 1;
            }
        }
    }
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            std::cout << table[i][j] << " ";
        }
        std::cout << std::endl;
    }
    
    return 0;
}