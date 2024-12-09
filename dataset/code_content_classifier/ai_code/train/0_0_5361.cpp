#include <iostream>
#include <vector>

int main() {
    int n;
    
    while (std::cin >> n && n != 0) {
        std::vector<int> incomes(n);
        int sum = 0;
        
        for (int i = 0; i < n; i++) {
            std::cin >> incomes[i];
            sum += incomes[i];
        }
        
        int avg = sum / n;
        int count = 0;
        
        for (int i = 0; i < n; i++) {
            if (incomes[i] <= avg) {
                count++;
            }
        }
        
        std::cout << count << std::endl;
    }
    
    return 0;
}