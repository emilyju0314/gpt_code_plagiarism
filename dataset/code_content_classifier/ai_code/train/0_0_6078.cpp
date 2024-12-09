#include <iostream>
#include <string>

int digitSum(int num) {
    int sum = 0;
    while(num > 0) {
        sum += num % 10;
        num /= 10;
    }
    return sum;
}

int main() {
    int t;
    std::cin >> t;

    for(int i = 0; i < t; i++) {
        int n, k;
        std::cin >> n >> k;

        int found = -1;
        for(int x = 0; x <= n; x++) {
            int sum = 0;
            for(int j = 0; j <= k; j++) {
                sum += digitSum(x + j);
            }
            if(sum == n) {
                found = x;
                break;
            }
        }

        std::cout << found << std::endl;
    }

    return 0;
}