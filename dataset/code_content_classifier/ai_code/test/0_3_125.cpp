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

    int current_number = 1;
    for(int i = 0; i < n; i++) {
        if(a[i] == 0) {
            a[i] = current_number;
            current_number = (current_number % n) + 1;
        }
    }

    for(int i = 0; i < n; i++) {
        std::cout << a[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}