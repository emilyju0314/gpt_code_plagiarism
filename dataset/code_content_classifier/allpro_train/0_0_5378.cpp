#include <iostream>
#include <string>

int main() {
    int k;
    std::cin >> k;
    
    std::string sequence;
    for (int i = 1; sequence.length() < k; i++) {
        sequence += std::to_string(i);
    }
    
    std::cout << sequence[k-1] << std::endl;
    
    return 0;
}