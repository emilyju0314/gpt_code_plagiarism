#include <iostream>
#include <string>

int main() {
    int n;
    std::cin >> n;

    int m = 2 * n;
    std::string s, p;

    for (int i = 0; i < m; i++) {
        if (i < n) {
            s += 'a';
        } else {
            s += 'b';
        }
    }

    for (int i = 0; i < n; i++) {
        p += 'a';
        p += 'b';
    }

    std::cout << s << " " << p << std::endl;

    return 0;
}