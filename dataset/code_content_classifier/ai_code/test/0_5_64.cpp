#include <iostream>
#include <string>
#include <unordered_map>

int main() {
    std::string s;
    std::cin >> s;
    
    std::string x_str;
    std::cin >> x_str;
    long long x = std::stoll(x_str);
    
    std::unordered_map<long long, int> positions;
    int n = s.size();
    
    long long num = 0;
    for (int i = 0; i < n; ++i) {
        num = num * 10 + (s[i] - '0');
        if (i > 0) {
            if (positions.find(x - num) != positions.end()) {
                std::cout << positions[x - num] + 1 << " " << i + 1 << std::endl;
                std::cout << i + 1 << " " << i + 1 << std::endl;
                return 0;
            }
        }
        positions[num] = i;
        num %= x;
    }
    
    return 0;
}