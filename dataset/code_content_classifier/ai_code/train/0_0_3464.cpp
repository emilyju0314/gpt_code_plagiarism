#include <iostream>
#include <algorithm>

void printPermutations(int n) {
    int arr[n];
    for(int i = 0; i < n; i++) {
        arr[i] = i + 1;
    }
    
    do {
        for(int i = 0; i < n; i++) {
            std::cout << arr[i] << " ";
        }
        std::cout << std::endl;
    } while(std::next_permutation(arr, arr + n));
}

int main() {
    int n;
    std::cin >> n;
    
    printPermutations(n);
    
    return 0;
}