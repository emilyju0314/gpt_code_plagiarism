#include <iostream>
#include <string>

int main() {
    int n;
    std::string animals;
    std::cin >> n >> animals;
    
    int numTigers = 0, numHamsters = 0;
    for(char c : animals) {
        if(c == 'T') {
            numTigers++;
        } else {
            numHamsters++;
        }
    }
    
    int swaps = 0;
    if(numTigers == numHamsters) {
        int curTigers = 0, curHamsters = 0;
        for(int i = 0; i < n; i++) {
            if(animals[i] == 'T') {
                curTigers++;
            } else {
                curHamsters++;
            }
            if(curTigers == numTigers) {
                if(curHamsters != 0) {
                    swaps++;
                }
                curTigers = 0;
                curHamsters = 0;
            }
            if(curHamsters == numHamsters) {
                if(curTigers != 0) {
                    swaps++;
                }
                curTigers = 0;
                curHamsters = 0;
            }
        }
    } else {
        std::cout << -1 << std::endl;
        return 0;
    }
    
    std::cout << swaps << std::endl;
    
    return 0;
}