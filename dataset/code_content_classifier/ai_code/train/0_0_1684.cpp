#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;
    
    std::vector<int> sequence(n);
    
    for(int i = 0; i < n; i++) {
        std::cin >> sequence[i];
    }
    
    std::vector<int> sortedSeq = sequence;
    std::sort(sortedSeq.begin(), sortedSeq.end());
    
    bool possible = true;
    for(int i = 0; i < n; i++) {
        if(sortedSeq[i] != sequence[i]) {
            possible = false;
            break;
        }
    }
    
    if(possible) {
        int i = n - 1;
        while(i >= 0 && sequence[i] == sortedSeq[n-1]) {
            i--;
        }
        
        std::cout << i + 1 << std::endl;
    } else {
        std::cout << -1 << std::endl;
    }
    
    return 0;
}