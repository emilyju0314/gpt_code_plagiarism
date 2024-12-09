#include <iostream>
#include <vector>

bool isRegularPolygon(int n, const std::vector<int>& moods) {
    for (int i = 0; i < n; ++i) {
        if (moods[i] != moods[(i + 1) % n]) {
            return false;
        }
    }
    return true;
}

int main() {
    int n;
    std::cin >> n;
    
    std::vector<int> moods(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> moods[i];
    }
    
    if (isRegularPolygon(n, moods)) {
        std::cout << "YES" << std::endl;
    } else {
        std::cout << "NO" << std::endl;
    }
    
    return 0;
}