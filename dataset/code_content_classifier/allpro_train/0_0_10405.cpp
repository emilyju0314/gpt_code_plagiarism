#include <iostream>
#include <set>
#include <unordered_map>

int main() {
    std::string s;
    std::cin >> s;
    
    int q;
    std::cin >> q;
    
    std::unordered_map<char, int> charCount;
    std::set<char> charSet;
    
    for (int i = 0; i < s.length(); i++) {
        charCount[s[i]]++;
        charSet.insert(s[i]);
    }
    
    for (int i = 0; i < q; i++) {
        int type;
        std::cin >> type;
        
        if (type == 1) {
            int pos;
            char c;
            std::cin >> pos >> c;
            
            char origC = s[pos-1];
            charCount[origC]--;
            if (charCount[origC] == 0) {
                charSet.erase(origC);
            }
            
            s[pos-1] = c;
            charCount[c]++;
            charSet.insert(c);
        } else {
            int l, r;
            std::cin >> l >> r;
            
            int count = 0;
            for (auto itr = charSet.begin(); itr != charSet.end(); itr++) {
                if (charCount[*itr] >= l && charCount[*itr] <= r) {
                    count++;
                }
            }
            std::cout << count << std::endl;
        }
    }
    
    return 0;
}