#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;
    
    std::vector<int> a(n);
    for(int i = 0; i < n; i++){
        std::cin >> a[i];
    }
    
    int min_pos, max_pos;
    min_pos = max_pos = 0;
    for(int i = 0; i < n; i++){
        if(a[i] == 1){
            min_pos = i;
        }
        if(a[i] == n){
            max_pos = i;
        }
    }
    
    int max_distance = std::max(std::max(max_pos, n-1-max_pos), std::max(min_pos, n-1-min_pos));
    
    if(min_pos < max_pos){
        std::cout << max_distance << std::endl;
    } else {
        std::cout << max_distance + 1 << std::endl;
    }
    
    return 0;
}