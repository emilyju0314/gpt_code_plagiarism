#include <iostream>

int main() {
    int n, m;
    std::cin >> n >> m;
    
    int sum = 0;
    for(int i = 0; i < m; i++) {
        int start, end;
        std::cin >> start >> end;
        
        sum += end - start + 1;
    }
    
    std::cout << sum << std::endl;
    
    return 0;
}