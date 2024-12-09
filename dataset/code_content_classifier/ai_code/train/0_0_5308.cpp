#include <iostream>
#include <vector>
#include <string>

int main() {
    int n;
    std::cin >> n;
    
    std::vector<std::string> phoneNumbers(n);
    
    for(int i = 0; i < n; i++) {
        std::cin >> phoneNumbers[i];
    }
    
    int length = phoneNumbers[0].length();
    
    for(int i = 1; i < n; i++) {
        int commonPrefixLength = 0;
        for(int j = 0; j < length; j++) {
            if(phoneNumbers[0][j] == phoneNumbers[i][j]) {
                commonPrefixLength++;
            } else {
                break;
            }
        }
        length = commonPrefixLength;
    }
    
    std::cout << length << std::endl;
    
    return 0;
}