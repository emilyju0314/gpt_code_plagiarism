#include <iostream>
#include <vector>
#include <algorithm>

void printSubsets(int n, int k, std::vector<int>& elements) {
    // Generate all possible subsets
    for(int i = 0; i < 1 << k; i++) {
        int subset = 0;
        std::vector<int> subsetElements;
        for(int j = 0; j < k; j++) {
            if(i & (1 << j)) {
                subset |= 1 << elements[j];
                subsetElements.push_back(elements[j]);
            }
        }
        // Check if the subset is a subset of T
        if(subset == (subset & ((1 << n) - 1))) {
            std::cout << subset << ": ";
            for(auto element : subsetElements) {
                std::cout << element << " ";
            }
            std::cout << std::endl;
        }
    }
}

int main() {
    int n, k;
    std::vector<int> elements;
    
    // Input the values of n and k
    std::cin >> n >> k;
    
    // Input the elements of T
    for(int i = 0; i < k; i++) {
        int element;
        std::cin >> element;
        elements.push_back(element);
    }
    
    // Sort the elements in ascending order
    std::sort(elements.begin(), elements.end());
    
    // Print all subsets of T
    printSubsets(n, k, elements);
    
    return 0;
}