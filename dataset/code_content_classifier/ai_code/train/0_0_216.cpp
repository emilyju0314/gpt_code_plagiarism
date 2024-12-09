#include <iostream>
#include <string>

int main() {
    int n;
    std::cin >> n;

    std::string s;
    std::cin >> s;

    std::string result = "";
    result += s[0]; // Add the first character to the result

    for(int i = 1; i < n; i++) {
        if((s[i] == 'e' || s[i] == 'o') && s[i] == s[i-1] && (i == n-1 || s[i] != s[i+1])) {
            result += s[i];
        } else if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' || s[i] == 'y') {
            if(s[i] != s[i-1]) {
                result += s[i];
            }
        } else {
            result += s[i];
        }
    }

    std::cout << result << std::endl;

    return 0;
}