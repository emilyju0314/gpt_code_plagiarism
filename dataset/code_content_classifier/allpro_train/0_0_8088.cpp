#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n, m, p;
    std::cin >> n >> m >> p;
    
    std::vector<int> a(n);
    std::vector<int> b(m);
    
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    
    for (int i = 0; i < m; i++) {
        std::cin >> b[i];
    }
    
    std::vector<int> positions;
    
    for (int q = 0; q <= n - m*p; q++) {
        std::vector<int> temp(a.begin() + q, a.begin() + q + m*p);
        std::sort(temp.begin(), temp.end());
        std::vector<int> sorted_b = b;
        std::sort(sorted_b.begin(), sorted_b.end());
        
        if (temp == sorted_b) {
            positions.push_back(q + 1);
        }
    }
    
    std::cout << positions.size() << std::endl;
    for (int idx : positions) {
        std::cout << idx << " ";
    }
    
    return 0;
}