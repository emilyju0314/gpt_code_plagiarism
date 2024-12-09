#include <iostream>
#include <list>

int main() {
    int n, k, m;
    
    while (true) {
        std::cin >> n >> k >> m;
        
        if (n == 0 && k == 0 && m == 0) {
            break;
        }
        
        std::list<int> stones;
        for (int i = 1; i <= n; i++) {
            stones.push_back(i);
        }
        
        std::list<int>::iterator current = stones.begin();
        
        while (stones.size() > 1) {
            for (int i = 0; i < m-1; i++) {
                current++;
                if (current == stones.end()) {
                    current = stones.begin();
                }
            }
            int stoneToRemove = *current;
            current = stones.erase(current);
            if (current == stones.end()) {
                current = stones.begin();
            }
            
            for (int i = 0; i < k-1; i++) {
                current++;
                if (current == stones.end()) {
                    current = stones.begin();
                }
            }
        }
        
        std::cout << stones.front() << std::endl;
    }
    
    return 0;
}