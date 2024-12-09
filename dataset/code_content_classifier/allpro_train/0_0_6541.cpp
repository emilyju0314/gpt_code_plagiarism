#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;
    
    std::vector<int> days(n);
    for(int i = 0; i < n; i++) {
        std::cin >> days[i];
    }
    
    int rest_count = 0;
    for(int i = 1; i < n-1; i++) {
        if((days[i-1] == 1 && days[i] == 3) || (days[i-1] == 3 && days[i] == 1)) {
            rest_count++;
            i++;
        }
    }
    
    std::cout << rest_count << std::endl;
    
    return 0;
}