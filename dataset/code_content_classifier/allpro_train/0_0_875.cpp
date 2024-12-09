#include <iostream>
#include <string>

int main() {
    int n;
    std::cin >> n;
    
    std::string s;
    std::cin >> s;

    int count = 0;

    for(int i = 0; i < n; i++) {
        if(s[i] == '+') {
            count++;
        } else {
            if(count > 0) {
                count--;
            }
        }
    }

    std::cout << count << std::endl;

    return 0;
}