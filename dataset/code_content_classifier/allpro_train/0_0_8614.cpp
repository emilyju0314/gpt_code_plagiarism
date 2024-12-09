#include <iostream>
#include <algorithm>

int main() {
    int a, b, c, d;
    char op1, op2, op3;

    // Input
    std::cin >> a >> b >> c >> d;
    std::cin >> op1 >> op2 >> op3;

    // Try all possible permutations of the numbers
    int nums[] = {a, b, c, d};
    int result = INT_MAX;
    do {
        int temp1, temp2, temp3;
        temp1 = (op1 == '+') ? nums[0] + nums[1] : nums[0] * nums[1];
        temp2 = (op2 == '+') ? temp1 + nums[2] : temp1 * nums[2];
        temp3 = (op3 == '+') ? temp2 + nums[3] : temp2 * nums[3];
        result = std::min(result, temp3);
    } while(std::next_permutation(nums, nums + 4));

    // Output
    std::cout << result << std::endl;

    return 0;
}