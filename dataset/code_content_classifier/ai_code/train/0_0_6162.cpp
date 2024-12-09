#include <iostream>
#include <string>

int main() {
    int t;
    std::cin >> t;
    
    while(t--) {
        std::string b;
        std::cin >> b;
        
        std::string a = "";
        
        for(int i = 0; i < b.length(); i += 2) {
            a += b[i];
        }
        
        a += b.back();
        
        std::cout << a << std::endl;
    }
    
    return 0;
}