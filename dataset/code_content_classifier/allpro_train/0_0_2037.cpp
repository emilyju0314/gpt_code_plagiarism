#include <iostream>
#include <string>

int HammingDistance(const std::string& s, const std::string& t) {
    int distance = 0;
    for (int i = 0; i < s.length(); i++) {
        distance += std::abs(s[i] - t[i]);
    }
    return distance;
}

int main() {
    std::string a, b;
    std::cin >> a >> b;

    int sum = 0;
    for (int i = 0; i <= b.length() - a.length(); i++) {
        sum += HammingDistance(a, b.substr(i, a.length()));
    }

    std::cout << sum << std::endl;

    return 0;
}