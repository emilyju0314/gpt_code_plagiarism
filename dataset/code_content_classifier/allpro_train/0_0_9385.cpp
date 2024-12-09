#include <iostream>
#include <string>

int main() {
    std::string s, t;
    std::cin >> s >> t;

    int pos = 1;
    for (int i = 0; i < t.size(); i++) {
        if (s[pos-1] == t[i]) {
            pos++;
        }
    }

    std::cout << pos << std::endl;

    return 0;
}