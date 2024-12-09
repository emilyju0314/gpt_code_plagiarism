// Below is the C++ program to solve the given problem

#include <iostream>
#include <string>

int countPN(int n, int m, std::string s) {
    int count = 0;
    for (int i = 0; i <= m - 2 * n - 1; i++) {
        bool isPN = true;
        for (int j = 0; j <= n; j++) {
            if (j % 2 == 0) {
                if (s[i + j] != 'O') {
                    isPN = false;
                    break;
                }
            } else {
                if (s[i + j] != 'I') {
                    isPN = false;
                    break;
                }
            }
        }
        if (isPN) {
            count++;
        }
    }
    return count;
}

int main() {
    while (true) {
        int n, m;
        std::string s;
        
        std::cin >> n;
        if (n == 0) {
            break;
        }
        
        std::cin >> m;
        std::cin >> s;
        
        int result = countPN(n, m, s);
        std::cout << result << std::endl;
    }
    return 0;
}