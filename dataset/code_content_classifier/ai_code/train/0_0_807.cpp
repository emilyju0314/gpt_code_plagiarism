#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for(int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    std::vector<int> sorted_a = a;
    std::sort(sorted_a.begin(), sorted_a.end());

    int count = 0;
    for(int i = 0; i < n; i++) {
        if(a[i] != sorted_a[i]) {
            count++;
        }
    }

    if(count <= 2) {
        std::cout << "YES" << std::endl;
    } else {
        std::cout << "NO" << std::endl;
    }

    return 0;
}