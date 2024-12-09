#include <iostream>
#include <string>

int main() {
    int n, m;
    std::cin >> n >> m;
    
    std::string s;
    std::cin >> s;
    
    for(int i = 0; i < m; i++) {
        int l, r;
        char c1, c2;
        std::cin >> l >> r >> c1 >> c2;
        
        for(int j = l-1; j < r; j++) {
            if(s[j] == c1) {
                s[j] = c2;
            }
        }
    }
    
    std::cout << s << std::endl;
    
    return 0;
}