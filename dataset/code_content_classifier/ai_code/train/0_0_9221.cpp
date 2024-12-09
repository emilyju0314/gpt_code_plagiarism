#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;
    
    std::vector<int> sequence(n);
    for (int i = 0; i < n; i++) {
        std::cin >> sequence[i];
    }

    int count_1 = std::count(sequence.begin(), sequence.end(), 1);
    int count_2 = std::count(sequence.begin(), sequence.end(), 2);
    int count_3 = std::count(sequence.begin(), sequence.end(), 3);

    int min_count = std::min({count_1, count_2, count_3});
    
    int replacements_needed = n - min_count;
    
    std::cout << replacements_needed << std::endl;

    return 0;
}