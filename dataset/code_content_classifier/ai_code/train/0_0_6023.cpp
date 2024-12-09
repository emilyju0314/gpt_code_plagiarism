#include <iostream>
#include <string>
#include <unordered_map>

int main() {
    std::string s;
    std::cin >> s;

    std::unordered_map<char, int> freq;
    for(char c : s)
        freq[c]++;

    int ans = 0;
    while(true) {
        if(freq['B'] >= 1 && freq['u'] >= 2 && freq['l'] >= 1 && freq['b'] >= 2 && freq['a'] >= 2 && freq['s'] >= 1 && freq['a'] >= 1 && freq['u'] >= 2 && freq['r'] >= 2) {
            freq['B']--;
            freq['u'] -= 2;
            freq['l']--;
            freq['b'] -= 2;
            freq['a'] -= 2;
            freq['s']--;
            freq['a']--;
            freq['u'] -= 2;
            freq['r'] -= 2;

            ans++;
        } else {
            break;
        }
    }

    std::cout << ans << std::endl;

    return 0;
}