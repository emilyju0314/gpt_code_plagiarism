#include <iostream>
#include <vector>
#include <algorithm>

bool isLucky(int num) {
    while(num > 0) {
        int digit = num % 10;
        if(digit != 4 && digit != 7) {
            return false;
        }
        num /= 10;
    }
    return true;
}

int main() {
    int n, k;
    std::cin >> n >> k;

    std::vector<int> permutation;
    for(int i = 1; i <= n; i++) {
        permutation.push_back(i);
    }

    int count = 0;
    do {
        int index = 1;
        for(int num : permutation) {
            if(isLucky(index) && isLucky(num)) {
                count++;
            }
            index++;
        }
        if(count == k) {
            break;
        }
    } while(std::next_permutation(permutation.begin(), permutation.end()));

    if(count == k) {
        std::cout << 1 << std::endl;
    } else {
        std::cout << -1 << std::endl;
    }

    return 0;
}