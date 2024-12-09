#include <iostream>
#include <string>
#include <set>

// Function to calculate f(x)
int fx(int x) {
    std::string s = std::to_string(x);
    std::string result(s.rbegin(), s.rend());
    
    // Remove leading zeroes
    while(result.length() > 1 && result[0] == '0') {
        result = result.substr(1);
    }
    return std::stoi(result);
}

// Function to calculate g(x)
int gx(int x) {
    return x / fx(fx(x));
}

int main() {
    int t;
    std::cin >> t;
    
    while(t--) {
        // Read the value of n
        std::string str_n;
        std::cin >> str_n;
        
        // Convert n to an integer
        int n = std::stoi(str_n);
        
        // Set to store different values of g(x)
        std::set<int> unique_values;
        
        // Calculate g(x) for each value of x from 1 to n
        for(int x = 1; x <= n; x++) {
            unique_values.insert(gx(x));
        }
        
        // Output the number of different values of g(x)
        std::cout << unique_values.size() << std::endl;
    }
    
    return 0;
}