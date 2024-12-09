#include <iostream>
#include <vector>
#include <algorithm>

std::string getLabel(std::string s, int m, long long k) {
    int n = s.length();
    std::vector<std::string> labels;
    
    for (int i = 1; i <= n - m + 1; i++) {
        std::string label = s.substr(0, i);
        for (int j = 1; j < m; j++) {
            label += s.substr(i, 1);
            i++;
        }
        labels.push_back(label);
    }
    
    std::sort(labels.begin(), labels.end(), std::greater<std::string>());
    
    return labels[k - 1];
}

int main() {
    int n, m;
    long long k;
    std::cin >> n >> m >> k;
    
    std::string s;
    std::cin >> s;
    
    std::cout << getLabel(s, m, k) << std::endl;
    
    return 0;
}