#include <iostream>
#include <string>
#include <set>

int main() {
    int t;
    std::cin >> t;

    while(t--) {
        int n;
        std::cin >> n;

        std::string s;
        std::cin >> s;

        std::set<char> seen;

        char mex = 'a';
        for(char c : s) {
            seen.insert(c);
            while(seen.count(mex) > 0) {
                mex++;
            }
        }

        std::cout << mex << std::endl;
    }

    return 0;
}