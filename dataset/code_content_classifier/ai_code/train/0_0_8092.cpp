#include <iostream>

int main() {
    int n, m;
    std::cin >> n >> m;
    
    int days = n;
    int remaining = n;
    
    for(int i = 1; remaining > 0; i++) {
        if(i % m == 0) {
            remaining++;
        }
        remaining--;
        days++;
    }
    
    std::cout << days << std::endl;

    return 0;
}