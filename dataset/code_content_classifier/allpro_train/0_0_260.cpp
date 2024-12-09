#include <iostream>
#include <string>

int main() {
    int n, x, y;
    std::cin >> n >> x >> y;
    
    std::string number;
    std::cin >> number;
    
    int operations = 0;
    for (int i = n-1; i >= n-x; --i) {
        if (i == n-y-1) {
            if (number[i] == '0') {
                operations++;
            }
        } else {
            if (number[i] == '1') {
                operations++;
            }
        }
    }
    
    std::cout << operations << std::endl;
    
    return 0;
}