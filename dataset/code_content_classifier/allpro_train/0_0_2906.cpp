#include <iostream>
#include <string>

int main() {
    std::string n;
    int k;
    std::cin >> n >> k;
    
    int count = 0;
    int zeros = 0;
    
    for(int i = n.size() - 1; i >= 0; i--){
        if(n[i] == '0'){
            zeros++;
        } else {
            count++;
        }
        
        if(zeros == k){
            break;
        }
    }
    
    if(zeros < k){
        count = n.size() - 1;
    }
    
    std::cout << count << std::endl;
    
    return 0;
} 

// Sample Input
// 30020 3

// Output
// 1