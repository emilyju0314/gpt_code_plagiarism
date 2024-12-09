#include <iostream>
#include <string>

int main() {
    int n;
    std::string s;
    std::cin >> n >> s;

    std::string decoded = "";
    int left = 0, right = s.length() - 1;
    bool isLeft = true;

    for (int i = 0; i < n; i++) {
        if (isLeft) {
            decoded = s[left] + decoded;
            left++;
        } else {
            decoded = s[right] + decoded;
            right--;
        }
        isLeft = !isLeft;
    }

    std::cout << decoded << std::endl;

    return 0;
}