#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    int count = 0;
    for(int i = 0; i < n; i++) {
        int k, b;
        std::cin >> k >> b;
        if(k != 0) {
            count++;
        }
    }

    std::cout << count << std::endl;

    return 0;
}