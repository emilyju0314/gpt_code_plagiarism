#include <iostream>
#include <vector>
#include <algorithm>

bool compareStrings(std::string a, std::string b) {
    return a + b < b + a;
}

int main() {
    int n;
    std::cin >> n;
    
    std::vector<std::string> strings(n);
    for (int i = 0; i < n; i++) {
        std::cin >> strings[i];
    }
    
    std::sort(strings.begin(), strings.end(), compareStrings);
    
    std::string result;
    for (int i = 0; i < n; i++) {
        result += strings[i];
    }
    
    std::cout << result << std::endl;
    
    return 0;
}