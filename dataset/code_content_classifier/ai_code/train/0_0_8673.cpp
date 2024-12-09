#include <iostream>
#include <string>
#include <vector>

int main() {
    std::vector<int> p(26);
    std::string s, t;
    std::vector<int> idx_s(26), idx_t(26);
    
    for (int i = 0; i < 26; i++) {
        std::cin >> p[i];
    }
    
    std::cin >> s >> t;
    
    for (int i = 0; i < s.length(); i++) {
        idx_s[s[i] - 'a'] = i + 1;
    }
    
    for (int i = 0; i < t.length(); i++) {
        idx_t[t[i] - 'a'] = i + 1;
    }
    
    std::string result = "";
    
    for (int i = 0; i <= t.length() - s.length(); i++) {
        bool occurrence = true;
        for (int j = 0; j < s.length(); j++) {
            if (s[j] != t[i + j] && p[idx_s[s[j] - 'a'] - 1] != idx_t[t[i + j] - 'a']) {
                occurrence = false;
                break;
            }
        }
        result += (occurrence ? "1" : "0");
    }
    
    std::cout << result << std::endl;
    
    return 0;
}