#include <iostream>
#include <vector>
#include <string>

int main() {
    int W, Q;
    
    while (true) {
        std::cin >> W >> Q;
        
        if (W == 0 && Q == 0) {
            break;
        }
        
        std::vector<int> napSpots(W, -1);
        
        std::string action;
        int id, w;
        
        for (int i = 0; i < Q; i++) {
            std::cin >> action >> id;
            
            if (action == "s") {
                std::cin >> w;
                
                bool napTaken = false;
                for (int j = 0; j <= W - w; j++) {
                    bool spaceAvailable = true;
                    for (int k = j; k < j + w; k++) {
                        if (napSpots[k] != -1) {
                            spaceAvailable = false;
                            break;
                        }
                    }
                    if (spaceAvailable) {
                        for (int k = j; k < j + w; k++) {
                            napSpots[k] = id;
                        }
                        std::cout << j << std::endl;
                        napTaken = true;
                        break;
                    }
                }
                if (!napTaken) {
                    std::cout << "impossible" << std::endl;
                }
            } else if (action == "w") {
                for (int j = 0; j < W; j++) {
                    if (napSpots[j] == id) {
                        napSpots[j] = -1;
                    }
                }
            }
        }
        
        std::cout << "END" << std::endl;
    }
    
    return 0;
}