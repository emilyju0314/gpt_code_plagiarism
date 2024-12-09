#include <iostream>
#include <vector>

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

int main() {
    int n;
    std::cin >> n;

    std::vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        std::cin >> nums[i];
    }

    int gcd_all = nums[0];
    for (int i = 1; i < n; i++) {
        gcd_all = gcd(gcd_all, nums[i]);
    }

    int result = -1;
    for (int i = 0; i < n; i++) {
        int temp = nums[i];
        nums[i] = 0;

        int new_gcd = nums[0];
        for (int j = 1; j < n; j++) {
            new_gcd = gcd(new_gcd, nums[j]);
        }

        if (new_gcd > gcd_all) {
            result = 1;
            break;
        }

        nums[i] = temp;
    }

    std::cout << result << std::endl;

    return 0;
}