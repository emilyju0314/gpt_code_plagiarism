#include <iostream>
#include <vector>
#include <bitset>

int main() {
    int n;
    std::cin >> n;
    
    std::vector<std::bitset<64>> masks(n);
    for(int i = 0; i < n; i++) {
        int k;
        std::cin >> k;
        for(int j = 0; j < k; j++) {
            int b;
            std::cin >> b;
            masks[i].set(b);
        }
    }
    
    int q;
    std::cin >> q;
    
    for(int i = 0; i < q; i++) {
        int operation, m;
        std::cin >> operation >> m;
        
        std::bitset<64> state;
        
        if(operation == 0) {
            // test(i)
            std::cout << masks[m].test(m) << "\n";
        } else if(operation == 1) {
            // set(m)
            state |= masks[m];
            std::cout << state << "\n";
        } else if(operation == 2) {
            // clear(m)
            state &= ~masks[m];
            std::cout << state << "\n";
        } else if(operation == 3) {
            // flip(m)
            state ^= masks[m];
            std::cout << state << "\n";
        } else if(operation == 4) {
            // all(m)
            std::cout << (state & masks[m]) == masks[m] << "\n";
        } else if(operation == 5) {
            // any(m)
            std::cout << (state & masks[m]).any() << "\n";
        } else if(operation == 6) {
            // none(m)
            std::cout << (state & masks[m]).none() << "\n";
        } else if(operation == 7) {
            // count(m)
            std::cout << (state & masks[m]).count() << "\n";
        } else if(operation == 8) {
            // val(m)
            std::cout << (state & masks[m]).to_ulong() << "\n";
        }
    }
    
    return 0;
}