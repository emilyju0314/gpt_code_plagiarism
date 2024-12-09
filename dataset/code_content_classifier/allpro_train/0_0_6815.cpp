#include <iostream>
#include <unordered_set>

int main() {
    int N;
    std::cin >> N;

    std::unordered_set<int> uniqueElements;
    bool pairwiseDistinct = true;

    for (int i = 0; i < N; i++) {
        int num;
        std::cin >> num;
        
        if (uniqueElements.count(num) > 0) {
            pairwiseDistinct = false;
            break;
        } else {
            uniqueElements.insert(num);
        }
    }

    if (pairwiseDistinct) {
        std::cout << "YES" << std::endl;
    } else {
        std::cout << "NO" << std::endl;
    }

    return 0;
}