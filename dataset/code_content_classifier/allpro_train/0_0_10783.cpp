#include <iostream>
#include <string>

int main() {
    int n;
    std::cin >> n;
    
    std::string path1, path2;
    std::cin >> path1 >> path2;
    
    for(int i = 0; i < n-1; i++) {
        if((path1[i] == 'N' && path2[i] != 'S') ||
           (path1[i] == 'S' && path2[i] != 'N') ||
           (path1[i] == 'E' && path2[i] != 'W') ||
           (path1[i] == 'W' && path2[i] != 'E')) {
            std::cout << "NO" << std::endl;
            return 0;
        }
    }
    
    std::cout << "YES" << std::endl;
    
    return 0;
}