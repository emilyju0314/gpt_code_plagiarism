#include <iostream>
#include <vector>
#include <unordered_map>

int main() {
    int size;
    
    while(true) {
        std::cin >> size;
        
        if(size == 0) {
            break;
        }
        
        std::vector<int> A(size);
        std::unordered_map<int, int> count;
        
        for(int i = 0; i < size; i++) {
            std::cin >> A[i];
            count[A[i]]++;
        }
        
        bool found = false;
        for(auto elem : count) {
            if(elem.second > size / 2) {
                std::cout << elem.first << std::endl;
                found = true;
                break;
            }
        }
        
        if(!found) {
            std::cout << "NO COLOR" << std::endl;
        }
    }
    
    return 0;
}