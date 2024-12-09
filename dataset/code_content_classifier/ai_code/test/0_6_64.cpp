#include <iostream>
#include <string>
#include <unordered_map>

int main() {
    std::string s;
    std::cin >> s;
    
    std::string x_str;
    std::cin >> x_str;
    long long x = stoll(x_str);
    
    std::unordered_map<long long, int> pos;
    for(int i = 0; i < s.length(); ++i) {
        long long num = 0;
        for(int j = i; j < s.length(); ++j) {
            num = num * 10 + (s[j] - '0');
            if(num != 0 && num + pos[num] == x) {
                std::cout << i+1 << " " << j+1 << std::endl;
                std::cout << j+2 << " " << j+1+pos[num] << std::endl;
                return 0;
            }
            pos[num] = j-i;
        }
    }

    return 0;
}