#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;
    
    std::vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }
    
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }
    
    std::vector<int> indices;
    for (int i = 0; i < n; i++) {
        if ((sum - arr[i]) % (n-1) == 0 && arr[i] == (sum - arr[i]) / (n-1)) {
            indices.push_back(i+1);
        }
    }
    
    std::cout << indices.size() << "\n";
    for (int i = 0; i < indices.size(); i++) {
        std::cout << indices[i] << " ";
    }
    
    return 0;
}