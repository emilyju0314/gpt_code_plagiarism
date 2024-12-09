#include <iostream>
#include <vector>
#include <set>

int main() {
    int n;
    std::cin >> n;

    // Read the array elements
    std::vector<int> a(n);
    for(int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    // Find all possible XOR values
    std::set<int> possible_values;
    possible_values.insert(0); // Empty subsequence case
    std::set<int> temp;
    for(int i = 0; i < n; i++) {
        for(int val : possible_values) {
            temp.insert(val ^ a[i]);
        }
        possible_values.insert(temp.begin(), temp.end());
        temp.clear();
    }

    // Print the number of found x values
    std::cout << possible_values.size() << std::endl;

    // Print the found x values in increasing order
    for(int val : possible_values) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    return 0;
}