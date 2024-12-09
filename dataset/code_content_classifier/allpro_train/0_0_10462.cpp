#include <iostream>
#include <string>

int main() {
    std::string s;
    std::cin >> s;

    int start = 0, end = s.size() - 1;
    while (s[start] != 'A') start++;
    while (s[end] != 'Z') end--;

    int len = end - start + 1;
    std::cout << len << std::endl;

    return 0;
}