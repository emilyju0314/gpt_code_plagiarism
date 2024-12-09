#include <iostream>
#include <string>

int main() {
    int N;
    std::string S0, T;
    
    // Input N, S0, and T
    std::cin >> N >> S0 >> T;
    
    // Initialize variables
    int changes = 0;
    int result = 0;
    
    // Check if S0 is already equal to T
    if(S0 == T) {
        std::cout << 0 << std::endl;
        return 0;
    }
    
    // Check if T can be obtained by any number of changes to S0
    for(int i = 0; i < N; i++) {
        if(S0[i] != T[i]) {
            changes++;
        }
    }
    
    // If T can be obtained by changing some characters of S0
    if(changes != 0) {
        for(int i = 0; i < N; i++) {
            // Check if by changing i characters of S0, we get T
            std::string test = S0;
            for(int j = 0; j < i; j++) {
                test[j] = T[j];
            }
            
            int test_changes = 0;
            for(int j = 0; j < N; j++) {
                if(test[j] != T[j]) {
                    test_changes++;
                }
            }
            
            if(test_changes == changes) {
                result = i;
                break;
            }
        }
    }
    
    // Output the result
    if(changes == 0) {
        std::cout << 0 << std::endl;
    } else if(result != 0) {
        std::cout << result << std::endl;
    } else {
        std::cout << -1 << std::endl;
    }
    
    return 0;
}