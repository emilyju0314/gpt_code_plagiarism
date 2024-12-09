#include <iostream>
#include <string>

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        std::string s;
        std::cin >> s;

        int n = s.length();
        
        // Count the frequency of each digit in the string
        int freq[10] = {0};
        for (char c : s) {
            freq[c - '0']++;
        }
        
        // Find the digit that appears the most in the string
        int max_freq = 0;
        for (int i = 0; i < 10; i++) {
            max_freq = std::max(max_freq, freq[i]);
        }
        
        std::cout << n - max_freq << std::endl;
    }

    return 0;
}