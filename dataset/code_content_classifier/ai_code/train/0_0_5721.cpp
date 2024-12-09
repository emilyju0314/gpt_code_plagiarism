#include <iostream>
#include <string>

int main() {
    std::string s;
    std::cin >> s;

    int n = s.size();
    int openingBracket = -1;
    int closingBracket = -1;
    
    for (int i = 0; i < n; i++) {
        if (s[i] == '[' && openingBracket == -1) {
            openingBracket = i;
        }
        if (s[i] == ']' && closingBracket == -1) {
            closingBracket = i;
        }
    }

    if (openingBracket == -1 || closingBracket == -1 || openingBracket >= closingBracket) {
        std::cout << -1;
        return 0;
    }

    int colon1 = -1;
    int colon2 = -1;

    for (int i = openingBracket + 1; i < closingBracket; i++) {
        if (s[i] == ':') {
            colon1 = i;
            break;
        }
    }

    if (colon1 == -1) {
        std::cout << -1;
        return 0;
    }

    for (int i = colon1 + 1; i < closingBracket; i++) {
        if (s[i] == ':') {
            colon2 = i;
            break;
        }
    }

    if (colon2 == -1 || colon2 <= colon1) {
        std::cout << -1;
        return 0;
    }

    int maxLength = 4;

    for (int i = colon1 + 1; i < colon2; i++) {
        if (s[i] == '|') {
            maxLength++;
        }
    }

    std::cout << maxLength;

    return 0;
}