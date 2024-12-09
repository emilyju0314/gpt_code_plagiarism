#include <iostream>

int main() {
    int n;
    std::cin >> n;
    
    int numbers[n];
    for(int i = 0; i < n; i++) {
        std::cin >> numbers[i];
    }
    
    int evenCount = 0, oddCount = 0, evenIndex, oddIndex;
    for(int i = 0; i < n; i++) {
        if(numbers[i] % 2 == 0) {
            evenCount++;
            evenIndex = i + 1;
        } else {
            oddCount++;
            oddIndex = i + 1;
        }
    }
    
    if(evenCount == 1) {
        std::cout << evenIndex;
    } else {
        std::cout << oddIndex;
    }
    
    return 0;
}