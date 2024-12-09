#include <iostream>
#include <string>
#include <unordered_map>

bool isAnagram(std::string s, std::string p) {
    std::unordered_map<char, int> freqP;
    std::unordered_map<char, int> freqS;

    for (char c : p) {
        freqP[c]++;
    }

    int left = 0, right = 0, count = 0;
    while (right < s.length()) {
        if (++freqS[s[right]] <= freqP[s[right]]) {
            count++;
        }

        if (right - left + 1 == p.length()) {
            if (count == p.length()) {
                return true;
            }

            if (--freqS[s[left]] < freqP[s[left]]) {
                count--;
            }

            left++;
        }

        right++;
    }

    return false;
}

int main() {
    std::string s, p;
    std::cin >> s >> p;

    int goodSubstrings = 0;
    for (int i = 0; i < s.length(); i++) {
        if (isAnagram(s.substr(i, p.length()), p)) {
            goodSubstrings++;
        }
    }

    std::cout << goodSubstrings << std::endl;

    return 0;
}