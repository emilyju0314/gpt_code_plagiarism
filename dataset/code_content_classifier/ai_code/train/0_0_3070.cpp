#include <iostream>
#include <string>

const int MOD = 10007;

int main() {
    std::string s;
    std::cin >> s;
    
    int n;
    std::cin >> n;

    int len = s.length();
    
    int total_palindromes = 26; // 26 possibilities for each position
    
    for(int i = 1; i < n; i++) {
        total_palindromes = (total_palindromes * 26) % MOD; // Multiply by 26 for each position
    }
    
    std::cout << total_palindromes << std::endl;
    
    return 0;
}