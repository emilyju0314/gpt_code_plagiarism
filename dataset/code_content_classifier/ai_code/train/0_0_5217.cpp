#include <iostream>
#include <string>

std::string getLCM(std::string s, std::string t) {
    std::string result = "";
    int s_len = s.length();
    int t_len = t.length();
    
    int lcm = (s_len * t_len) / __gcd(s_len, t_len);

    for (int i = 0; i < lcm; i += s_len) {
        result += s;
    }

    if (result.find(t) == std::string::npos) {
        return "-1";
    }

    return result;
}

int main() {
    int q;
    std::cin >> q;

    for (int i = 0; i < q; i++) {
        std::string s, t;
        std::cin >> s >> t;

        std::cout << getLCM(s, t) << std::endl;
    }

    return 0;
}