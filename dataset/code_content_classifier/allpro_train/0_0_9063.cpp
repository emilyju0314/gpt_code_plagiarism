#include <iostream>
#include <string>
#include <map>

int main() {
    int n;
    std::cin >> n;

    std::map<char, int> charToInt;
    charToInt['a'] = 1;
    charToInt['b'] = 0;
    charToInt['c'] = 2;
    charToInt['d'] = 3;
    charToInt['e'] = 4;
    charToInt['f'] = 5;
    charToInt['g'] = 6;
    charToInt['h'] = 7;
    charToInt['i'] = 8;
    charToInt['j'] = 9;

    int index = 1;
    std::map<char, int> digitToInt;
    for (char c = 'a'; c <= 'j'; c++) {
        digitToInt[c] = index++;
    }

    int sum = 0;
    for (int i = 0; i < n; i++) {
        std::string s;
        std::cin >> s;

        int num = 0;
        for (char c : s) {
            num = num * 10 + digitToInt[c];
        }

        sum += num;
    }

    std::cout << sum << std::endl;

    return 0;
}