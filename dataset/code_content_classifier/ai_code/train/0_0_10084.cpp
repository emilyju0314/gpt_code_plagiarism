#include <iostream>
#include <vector>

int main() {
    int n, m;
    std::cin >> n >> m;
    
    std::vector<int> buttons(m);
    for (int i = 0; i < m; i++) {
        std::cin >> buttons[i];
    }
    
    std::vector<int> result(n, 0);
    
    for (int i = 0; i < m; i++) {
        for (int j = buttons[i]-1; j < n; j++) {
            if (result[j] == 0) {
                result[j] = buttons[i];
            }
        }
    }
    
    for (int i = 0; i < n; i++) {
        std::cout << result[i] << " ";
    }
    
    return 0;
}