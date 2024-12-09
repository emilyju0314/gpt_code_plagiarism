#include <iostream>
#include <string>
#include <unordered_map>

int main() {
    std::string s;
    std::cin >> s;
    
    std::string x_str;
    std::cin >> x_str;
    
    long long x;
    std::stringstream(x_str) >> x;
    
    std::unordered_map<long long, int> last_seen;
    
    int start_a = -1;
    int end_a = -1;
    
    for (int i = 0; i < s.size() - 1; ++i) {
        if (s[i] == '0') continue;
        
        long long num = s[i] - '0';
        for (int j = i + 1; j < s.size(); ++j) {
            num = num * 10 + (s[j] - '0');
            
            if (num == x) {
                start_a = i + 1;
                end_a = j + 1;
                break;
            } else if (num > x) {
                break;
            }
        }
        
        if (start_a != -1) break;
    }
    
    std::cout << start_a << " " << start_a + 1 << std::endl;
    std::cout << end_a << " " << end_a + 1 << std::endl;
    
    return 0;
}