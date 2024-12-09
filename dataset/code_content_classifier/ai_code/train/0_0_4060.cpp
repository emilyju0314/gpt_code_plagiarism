#include <iostream>
#include <cmath>

int countRepresentations(int n) {
    int count = 0;
    
    for (int a = 1; a * a <= n; a++) {
        for (int b = a; a * a + b * b <= n; b++) {
            for (int c = b; a * a + b * b + c * c <= n; c++) {
                int d = sqrt(n - a * a - b * b - c * c);
                if (a * a + b * b + c * c + d * d == n && d >= c) {
                    count++;
                }
            }
        }
    }
    
    return count;
}

int main() {
    int n;
    
    while (true) {
        std::cin >> n;
        
        if (n == 0) {
            break;
        }
        
        int result = countRepresentations(n);
        std::cout << result << std::endl;
    }
    
    return 0;
}