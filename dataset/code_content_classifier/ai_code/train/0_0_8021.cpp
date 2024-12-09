#include <iostream>
#include <string>

int main() {
    int n;
    std::string days;
    
    std::cin >> n;
    std::cin >> days;
    
    int s_to_f = 0;
    int f_to_s = 0;
    
    for(int i = 0; i < n - 1; i++) {
        if(days[i] == 'S' && days[i+1] == 'F') {
            s_to_f++;
        } else if(days[i] == 'F' && days[i+1] == 'S') {
            f_to_s++;
        }
    }
    
    if(s_to_f > f_to_s) {
        std::cout << "YES" << std::endl;
    } else {
        std::cout << "NO" << std::endl;
    }
    
    return 0;
}