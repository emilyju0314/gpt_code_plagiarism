#include <iostream>
#include <vector>

int main() {
    int n, k;
    std::cin >> n >> k;

    std::string s;
    std::cin >> s;

    for (int i = 0; i < k; ++i) {
        bool changed = false;
        for (int j = 0; j < n - 1; ++j) {
            if (s[j] == '4' && s[j+1] == '7') {
                if (j % 2 == 0) {
                    s[j+1] = '4';
                } else {
                    if (j > 0 && s[j-1] == '4') {
                        if ((k-i) % 2 == 0) {
                            break;
                        } else {
                            s[j] = '7';
                            break;
                        }
                    } else {
                        s[j] = '7';
                    }
                }
                changed = true;
                break;
            }
        }
        if (!changed) break;
    }

    std::cout << s << std::endl;

    return 0;
}