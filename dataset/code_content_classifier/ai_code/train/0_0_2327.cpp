#include <iostream>
#include <string>

int main() {
    std::string serveRecord;
    
    while (true) {
        std::cin >> serveRecord;
        
        if (serveRecord == "0") {
            break;
        }
        
        int scoreA = 0, scoreB = 0;
        int serveCount = 0;
        
        char prevServe = serveRecord[0];
        
        for (char c : serveRecord) {
            if (c == 'A') {
                scoreA++;
            } else if (c == 'B') {
                scoreB++;
            }
            
            serveCount++;
            
            // Check for game end
            if ((scoreA >= 11 || scoreB >= 11) && (std::abs(scoreA - scoreB) >= 2)) {
                if (scoreA > scoreB) {
                    std::cout << "11 " << scoreB << std::endl;
                } else {
                    std::cout << scoreA << " 11" << std::endl;
                }
                
                // Reset scores and serve count
                scoreA = 0;
                scoreB = 0;
                serveCount = 0;
            }
            
            prevServe = c;
        }
        
        // Output remaining scores
        if (scoreA > scoreB) {
            std::cout << "11 " << scoreB << std::endl;
        } else {
            std::cout << scoreA << " 11" << std::endl;
        }
    }
    
    return 0;
}