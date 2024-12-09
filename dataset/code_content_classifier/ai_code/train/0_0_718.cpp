#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    std::vector<int> b(n);
    
    for(int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    for(int i = 0; i < n; i++) {
        std::cin >> b[i];
    }

    std::vector<int> shifts(n);

    for(int i = 0; i < n; i++) {
        int min_dist = n;
        for(int j = 0; j < n; j++) {
            min_dist = std::min(min_dist, std::abs(j - (std::find(b.begin(), b.end(), a[i]) - b.begin())));
            std::rotate(b.begin(), b.begin() + 1, b.end());
        }
        shifts[i] = min_dist;
    }

    for(int shift : shifts) {
        std::cout << shift << std::endl;
    }

    return 0;
}