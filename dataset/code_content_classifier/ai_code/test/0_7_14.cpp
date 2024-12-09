#include <iostream>
#include <vector>

std::vector<int> sortArray(std::vector<int>& a) {
    std::vector<int> actions;
    int n = a.size();
    
    for (int i = 0; i < n; i++) {
        for (int j = n-1; j > i; j--) {
            if (a[j-1] > a[j]) {
                std::swap(a[j-1], a[j]);
                actions.push_back(j-1);
                actions.push_back(j);
                actions.push_back(j-i);
            }
        }
    }
    
    return actions;
}

int main() {
    int t;
    std::cin >> t;
    
    while (t--) {
        int n;
        std::cin >> n;
        std::vector<int> a(n);
        
        for (int i = 0; i < n; i++) {
            std::cin >> a[i];
        }
        
        std::vector<int> actions = sortArray(a);
        
        std::cout << actions.size() / 3 << "\n";
        for (int i = 0; i < actions.size(); i += 3) {
            std::cout << actions[i] + 1 << " " << actions[i+1] + 1 << " " << actions[i+2] << "\n";
        }
    }
    
    return 0;
}