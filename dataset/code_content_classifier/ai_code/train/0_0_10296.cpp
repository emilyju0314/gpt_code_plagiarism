#include <iostream>
#include <vector>

int main() {
    int q, lim;
    
    while (std::cin >> q >> lim) {
        if (q == 0 && lim == 0) {
            break;
        }
        
        std::vector<int> individuals;
        
        for (int i = 0; i < q; i++) {
            int query, x;
            std::cin >> query >> x;
            
            if (query == 0) {
                individuals.push_back(x);
            } else if (query == 1) {
                if (x <= individuals.size()) {
                    individuals.erase(individuals.begin() + x - 1);
                }
            } else if (query == 2) {
                if (x <= individuals.size()) {
                    std::cout << individuals[x - 1] << std::endl;
                }
            } else if (query == 3) {
                individuals.erase(std::remove(individuals.begin(), individuals.end(), x), individuals.end());
            }
        }
        
        std::cout << "end" << std::endl;
    }
    
    return 0;
}