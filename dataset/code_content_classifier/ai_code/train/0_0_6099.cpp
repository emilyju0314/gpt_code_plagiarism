#include <iostream>
#include <string>

int main() {
    std::string s, t;
    std::cin >> s >> t;

    int n = s.length();

    for(int i = n-1; i >= 0; i--) {
        if(s[i] != 'z') {
            s[i]++;
            break;
        } else {
            s[i] = 'a';
        }
    }

    if(s >= t) {
        std::cout << "No such string" << std::endl;
    } else {
        std::cout << s << std::endl;
    }

    return 0;
}