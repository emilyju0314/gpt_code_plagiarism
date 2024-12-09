#include <iostream>
#include <string>

int main() {
    int t;
    std::cin >> t;

    for(int i = 0; i < t; i++) {
        int n;
        std::cin >> n;

        std::string s;
        std::cin >> s;

        std::string answer = "";
        bool last_zero = false;

        for(int j = 0; j < s.size(); j++) {
            if(s[j] == '0') {
                if(last_zero) {
                    continue;
                } else {
                    answer += '0';
                    last_zero = true;
                }
            } else {
                answer += '1';
                last_zero = false;
            }
        }

        std::cout << answer << std::endl;
    }

    return 0;
}