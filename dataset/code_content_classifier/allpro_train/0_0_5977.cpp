#include <iostream>

int main() {
    std::string input;
    
    while (true) {
        std::cin >> input;
        
        if (input == "start") {
            int a = 1;
            bool found = false;
            
            // Binary search to find the number a
            int left = 1, right = 1e9;
            while (left <= right) {
                int mid = (left + right) / 2;
                
                // Ask a question
                std::cout << "? " << mid * 2 << " " << mid << std::endl;
                
                std::cin >> input;
                
                if (input == "y") {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                    a = mid;
                    found = true;
                }
            }
            
            if (found) {
                std::cout << "! " << a << std::endl;
                std::cout << std::flush;
            } else {
                std::cout << "e" << std::endl;
                std::cout << std::flush;
            }
            
        } else if (input == "end") {
            break;
        } else if (input == "mistake") {
            break; // Terminate in case of a mistake
        }
    }
    
    return 0;
}