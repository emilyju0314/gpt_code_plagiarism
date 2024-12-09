#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int f(const std::string& a, const std::string& b) {
    if(a.size() != b.size()) {
        return 1337;
    }
    
    std::string sorted_a = a;
    std::sort(sorted_a.begin(), sorted_a.end());
    
    std::string sorted_b = b;
    std::sort(sorted_b.begin(), sorted_b.end());
    
    if(sorted_a != sorted_b) {
        return 1337;
    } 
    
    return 0;
}

int main() {
    int n;
    std::cin >> n;
    
    std::vector<std::string> strings(n);
    
    for(int i = 0; i < n; i++) {
        std::cin >> strings[i];
    }
    
    long long sum = 0;
    
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            sum += f(strings[i], strings[j]);
        }
    }
    
    std::cout << sum << std::endl;
    
    return 0;
}