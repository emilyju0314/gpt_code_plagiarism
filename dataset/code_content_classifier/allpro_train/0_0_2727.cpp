#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;
    
    std::vector<int> petals(n);
    for(int i = 0; i < n; i++) {
        std::cin >> petals[i];
    }
    
    int max_petals = 0;
    for(int i = 0; i < n; i++) {
        if ((petals[i] % 2) != 0) {
            max_petals += petals[i];
        }
    }
    
    if ((max_petals % 2) == 0) {
        for (int i = 0; i < n; i++) {
            max_petals += petals[i];
            if ((max_petals % 2) == 0) {
                break;
            }
        }
    }
    
    std::cout << max_petals << std::endl;
    
    return 0;
}