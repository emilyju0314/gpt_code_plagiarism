#include <iostream>
#include <string>

int main() {
    int n;
    std::string fractions;
    
    // Input
    std::cin >> n;
    std::cin >> fractions;

    // Determine the party that will win
    while(n > 1) {
        std::string new_fractions = "";
        
        for(int i = 0; i < n; i++) {
            if(fractions[i] == 'D' || fractions[i] == 'R') {
                bool to_remove = false;
                for(int j = 0; j < i; j++) {
                    if(fractions[j] == (fractions[i] == 'D' ? 'R' : 'D')) {
                        to_remove = true;
                        break;
                    }
                }
                if(!to_remove) {
                    new_fractions += fractions[i];
                }
            }
        }
        
        fractions = new_fractions;
        n = fractions.size();
    }
    
    // Output
    std::cout << fractions[0] << std::endl;

    return 0;
}