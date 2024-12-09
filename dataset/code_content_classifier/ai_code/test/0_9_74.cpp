#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;
    
    std::vector<int> b(n);
    for(int i = 0; i < n; i++) {
        std::cin >> b[i];
    }
    
    std::vector<int> a(n, 0);
    for(int i = 0; i < n-1; i++) {
        a[i] = b[i] + b[i+1];
    }
    
    int missing_element = a[0] - b[0];
    bool possible = true;
    for(int i = 0; i < n-1; i++) {
        if(b[i] != a[i] + missing_element) {
            possible = false;
            break;
        }
    }
    
    if(possible) {
        std::cout << "YES" << std::endl;
        for(int i = 0; i < n; i++) {
            std::cout << a[i] << " ";
        }
    } else {
        std::cout << "NO";
    }

    return 0;
}