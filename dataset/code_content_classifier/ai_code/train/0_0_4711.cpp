#include <iostream>

int main() {
    int n;
    std::cin >> n;

    int sum_upper = 0, sum_lower = 0;
    int odd_upper = 0, odd_lower = 0;

    for(int i = 0; i < n; i++) {
        int x, y;
        std::cin >> x >> y;
        sum_upper += x;
        sum_lower += y;

        if(x % 2 != 0) {
            odd_upper++;
        }
        if(y % 2 != 0) {
            odd_lower++;
        }
    }

    if(sum_upper % 2 == 0 && sum_lower % 2 == 0) {
        std::cout << "0" << std::endl;
    } else if((sum_upper % 2 == 0 && odd_upper > 0) || (sum_lower % 2 == 0 && odd_lower > 0)) {
        std::cout << "1" << std::endl;
    } else {
        std::cout << "-1" << std::endl;
    }

    return 0;
}