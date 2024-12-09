#include <iostream>
#include <string>

int main() {
    std::string s;
    std::cin >> s;

    bool changed = true;

    while(changed) {
        changed = false;

        for (int i = 0; i < s.length() - 1; i++) {
            if (s[i] == 'y' && s[i+1] == 'x') {
                std::swap(s[i], s[i+1]);
                changed = true;
                break;
            }
        }

        if (!changed) {
            for (int i = 0; i < s.length() - 1; i++) {
                if (s[i] == 'x' && s[i+1] == 'y') {
                    s.erase(i, 2);
                    changed = true;
                    break;
                }
            }
        }
    }

    std::cout << s << std::endl;

    return 0;
}