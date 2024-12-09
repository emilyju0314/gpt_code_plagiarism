#include <iostream>
#include <string>

int main() {
    int a;
    std::string s;
    
    std::cin >> a >> s;
    
    int n = s.size();
    int count = 0;
    
    for (int x = 0; x < n; x++) {
        for (int y = x; y < n; y++) {
            int sum = 0;
            for (int i = x; i <= y; i++) {
                for (int j = i; j <= y; j++) {
                    sum += (s[i] - '0') * (s[j] - '0');
                }
            }
            if (sum == a) {
                count++;
            }
        }
    }
    
    std::cout << count << std::endl;
    
    return 0;
}