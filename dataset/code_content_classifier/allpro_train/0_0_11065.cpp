#include <iostream>
#include <vector>
#include <string>

int main() {
    int n;
    std::cin >> n;
  
    std::vector<std::string> names(n);
    for(int i = 0; i < n; i++) {
        std::cin >> names[i];
    }
  
    std::vector<int> count(5, 0);
  
    for(const auto& name : names) {
        if(name[0] == 'M') count[0]++;
        else if(name[0] == 'A') count[1]++;
        else if(name[0] == 'R') count[2]++;
        else if(name[0] == 'C') count[3]++;
        else if(name[0] == 'H') count[4]++;
    }
  
    long long total_ways = 0;
  
    for(int i = 0; i < 5; i++) {
        for(int j = i + 1; j < 5; j++) {
            for(int k = j + 1; k < 5; k++) {
                total_ways += static_cast<long long>(count[i]) * count[j] * count[k];
            }
        }
    }
  
    std::cout << total_ways << std::endl;
  
    return 0;
}