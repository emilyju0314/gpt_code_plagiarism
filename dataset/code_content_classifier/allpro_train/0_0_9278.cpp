#include <iostream>
#include <string>

int main() {
    int n;
    std::cin >> n;

    std::string s, t;
    std::cin >> s >> t;

    std::string res = "";
    if (s[0] != t[0] && s[1] != t[1]) {
        res = "abc";
    } else if (s[0] != t[1] && s[1] != t[0]) {
        res = "acb";
    } else if (s[0] != t[0] && s[1] != t[1]) {
        res = "bac";
    } else {
        res = "bca";
    }

    for (int i = 0; i < n; i++) {
        std::cout << res;
    }

    return 0;
}