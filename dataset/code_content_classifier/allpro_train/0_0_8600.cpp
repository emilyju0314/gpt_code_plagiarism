#include <iostream>
#include <unordered_map>

int main() {
    int n, m;
    std::cin >> n;
    
    int arr[n+1];
    std::unordered_map<int, int> index;
    
    for (int i = 1; i <= n; i++) {
        std::cin >> arr[i];
        index[arr[i]] = i;
    }
    
    std::cin >> m;
    
    long long vasya = 0, petya = 0;
    
    for (int i = 0; i < m; i++) {
        int query;
        std::cin >> query;
        
        vasya += index[query];
        petya += n - index[query] + 1;
    }
    
    std::cout << vasya << " " << petya << std::endl;
    
    return 0;
}