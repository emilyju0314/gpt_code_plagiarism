#include <iostream>
#include <string>
#include <cmath>

double prettiness(std::string s) {
    const std::string vowels = "AEIOUY";
    int n = s.length();
    double sum = 0;
    
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            int vowels_count = 0;
            for (int k = i; k <= j; k++) {
                if (vowels.find(s[k]) != std::string::npos) {
                    vowels_count++;
                }
            }
            sum += (double)vowels_count / (j - i + 1);
        }
    }
    
    return sum;
}

int main() {
    std::string s;
    std::cin >> s;
    
    double result = prettiness(s);
    
    std::cout << result << std::endl;
    
    return 0;
}