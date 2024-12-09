#include <iostream>
#include <algorithm>

int main() {
    int A, B, C;
    std::cin >> A >> B >> C;

    // Try all possible permutations of A, B, and C
    int maximum_allowance = 0;
    do {
        int allowance = 10 * A + B + C; // Construct X + Y
        maximum_allowance = std::max(maximum_allowance, allowance); // Update maximum allowance
    } while (std::next_permutation(&A, &C+1)); // Generate the next permutation
    
    std::cout << maximum_allowance << std::endl;

    return 0;
}