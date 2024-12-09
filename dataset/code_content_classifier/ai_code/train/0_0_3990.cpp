#include <iostream>
#include <vector>
#include <cmath>

int main() {
    int n;
    std::cin >> n;
    
    std::vector<int> x(n/2);
    for (int i = 0; i < n/2; i++) {
        std::cin >> x[i];
    }
    
    std::vector<long long> sequence(n);
    sequence[1] = x[0];
    
    bool possible = true;
    
    for (int i = 2; i < n; i += 2) {
        int sum = sequence[i-1] + x[(i/2) - 1];
        int root = sqrt(sum);
        if (root * root == sum) {
            sequence[i] = x[(i/2) - 1];
            sequence[i+1] = root;
        } else {
            possible = false;
            break;
        }
    }
    
    if (!possible) {
        std::cout << "No" << std::endl;
    } else {
        std::cout << "Yes" << std::endl;
        for (int num : sequence) {
            std::cout << num << " ";
        }
        std::cout << std::endl;
    }
    
    return 0;
}