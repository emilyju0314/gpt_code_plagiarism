#include <iostream>
#include <string>

int main() {
    int n;
    std::cin >> n;

    std::string s;
    std::cin >> s;

    int count = 0;
    for(int i = 0; i < n; i++) {
        if((s[i] >= 'A' && s[i] <= 'M') || (s[i] >= 'a' && s[i] <= 'm')) {
            s[count++] = 'A';
        } else {
            s[count++] = 'N';
        }
    }

    std::cout << count << std::endl;
    for(int i = 0; i < count; i++) {
        std::cout << s[i];
    }
    std::cout << std::endl;

    return 0;
}