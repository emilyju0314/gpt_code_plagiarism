#include <iostream>
#include <string>

int main() {
    int n;
    std::string s;
    std::cin >> n >> s;

    std::string ans = "";
    bool removed = false;

    for(int i = 0; i < n-1; i++) {
        if(s[i] > s[i+1] && !removed) {
            removed = true;
        } else {
            ans += s[i];
        }
    }

    if(!removed) {
        ans += s[n-1];
    }

    std::cout << ans << std::endl;

    return 0;
}