#include <iostream>
#include <unordered_set>
#include <vector>

int main() {
    int n;
    std::cin >> n;
    
    std::vector<int> A(n);
    
    for (int i = 0; i < n; i++) {
        std::cin >> A[i];
    }
    
    std::unordered_set<int> unique_elements;
    std::vector<int> result;
    
    for (int i = 0; i < n; i++) {
        if (unique_elements.find(A[i]) == unique_elements.end()) {
            result.push_back(A[i]);
            unique_elements.insert(A[i]);
        }
    }
    
    for (int i = 0; i < result.size(); i++) {
        std::cout << result[i];
        if (i != result.size() - 1) {
            std::cout << " ";
        }
    }
    
    return 0;
}