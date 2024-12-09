#include <iostream>
#include <vector>

int main() {
    int n, t;
    std::cin >> n >> t;
    
    std::vector<int> a(n-1);
    for(int i = 0; i < n-1; i++) {
        std::cin >> a[i];
    }
    
    int current = 1;
    bool can_reach = false;
    while(current < t) {
        current += a[current-1]; // move to the next cell
        if(current == t) {
            can_reach = true;
            break;
        }
    }
    
    if(can_reach) {
        std::cout << "YES" << std::endl;
    } else {
        std::cout << "NO" << std::endl;
    }
    
    return 0;
}