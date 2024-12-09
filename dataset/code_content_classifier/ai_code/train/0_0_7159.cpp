#include <iostream>
#include <string>
#include <algorithm>

int main() {
    int n, k;
    std::cin >> n >> k;
    
    std::string s;
    std::cin >> s;
    
    std::sort(s.begin(), s.end());
    
    std::string t = s.substr(0, k);
    
    if(t.length() < k) {
        t += std::string(k - t.length(), t[0]); // fill with smallest letter
    } else {
        int i = k - 1;
        while(i >= 0 && t[i] == s[n - 1]) {
            i--;
        }
        if(i >= 0) {
            t[i] = s[s.find(t[i]) + 1]; // modify letter at position i
            while(++i < k) {
                t[i] = s[0]; // fill the rest with smallest letter
            }
        }
    }
    
    std::cout << t << std::endl;
    
    return 0;
}