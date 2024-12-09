#include <iostream>
#include <unordered_set>

int main() {
    int n, m;
    std::cin >> n >> m;

    int sum = 0;
    for (int i = 0; i < m; i++) {
        int a, b;
        std::cin >> a >> b;
        
        std::unordered_set<int> uniqueElements;
        uniqueElements.insert(a);
        uniqueElements.insert(b);
        
        for (int x : uniqueElements) {
            sum += x;
        }
    }
    
    std::cout << sum << std::endl;
    
    return 0;
}