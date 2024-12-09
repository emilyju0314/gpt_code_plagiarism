#include <iostream>
#include <vector>

bool isLuckyTicket(int n, const std::vector<int>& digits) {
    int sum = 0;
    for(int i = 0; i < n; i++) {
        sum += digits[i];
    }

    if(sum % 3 != 0) {
        return false;
    }

    sum /= 3;
    int curr_sum = 0, segments = 0;

    for(int i = 0; i < n - 1; i++) {
        curr_sum += digits[i];

        if(curr_sum == sum) {
            segments++;
            curr_sum = 0;
        }
    }

    if(segments >= 2) {
        return true;
    } else {
        return false;
    }
}

int main() {
    int n;
    std::cin >> n;

    std::vector<int> digits(n);
    for(int i = 0; i < n; i++) {
        std::cin >> digits[i];
    }

    if(isLuckyTicket(n, digits)) {
        std::cout << "YES" << std::endl;
    } else {
        std::cout << "NO" << std::endl;
    }

    return 0;
}