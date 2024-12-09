#include <iostream>
#include <vector>

int main() {
    int n, m;
    std::cin >> n;
    
    std::vector<int> A(n);
    for (int i = 0; i < n; i++) {
        std::cin >> A[i];
    }
    
    std::cin >> m;
    
    std::vector<int> B(m);
    for (int i = 0; i < m; i++) {
        std::cin >> B[i];
    }
    
    int result = 0;
    int minLength = n < m ? n : m;
    
    for (int i = 0; i < minLength; i++) {
        if (A[i] < B[i]) {
            result = 1;
            break;
        } else if (A[i] > B[i]) {
            break;
        }
    }
    
    if (result == 1 || (n < m && A == B)) {
        std::cout << "1" << std::endl;
    } else {
        std::cout << "0" << std::endl;
    }
    
    return 0;
}