#include <iostream>
#include <string>

using std::string;

int main() {
    int x, a, b, n;
    std::cin >> x >> a >> b >> n;

    for (int i = 0; i < n; ++i) {
        string s;
        std::cin >> s;
        if (s.front() == 'n') {
            x = std::max(0, x + a);
        } else if (s.front() == 't') {
            x = std::max(0, x + b);
        } else {
            x = 0;
        }
    }

    std::cout << x << std::endl;
    return 0;
}

