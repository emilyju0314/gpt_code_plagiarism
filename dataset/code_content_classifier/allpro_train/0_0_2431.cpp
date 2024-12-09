#include <iostream>
#include <set>

int main() {
    int n, m;
    std::cin >> n;
    
    std::set<int> A;
    for (int i = 0; i < n; i++) {
        int num;
        std::cin >> num;
        A.insert(num);
    }
    
    std::cin >> m;
    
    std::set<int> B;
    for (int i = 0; i < m; i++) {
        int num;
        std::cin >> num;
        B.insert(num);
    }
    
    std::set<int> difference;
    std::set_difference(A.begin(), A.end(), B.begin(), B.end(), std::inserter(difference, difference.begin()));
    
    for (int num : difference) {
        std::cout << num << std::endl;
    }
    
    return 0;
}