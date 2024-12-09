#include <iostream>
#include <string>

int distanceBetweenStrings(const std::string& s, const std::string& t) {
    if(s.size() != t.size()) {
        return -1; // strings are not of equal length
    }

    int distance = 0;
    for(int i = 0; i < s.size(); i++) {
        if(s[i] != t[i]) {
            distance++;
        }
    }

    return distance;
}

int main() {
    std::string S, T;
    std::cin >> S >> T;

    for(int i = 0; i <= S.size() - T.size(); i++) {
        std::string sub_s = S.substr(i, T.size());
        int result = distanceBetweenStrings(sub_s, T);
        std::cout << result << " ";
    }

    return 0;
}