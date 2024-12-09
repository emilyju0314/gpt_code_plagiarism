#include <iostream>
#include <vector>
#include <algorithm>

bool arrangeCakes(int W, std::vector<int>& radii) {
    int totalWidth = 0;
    for(int r : radii) {
        totalWidth += 2*r;
    }
    if(totalWidth <= W) {
        return true;
    }
    return false;
}

int main() {
    int W;
    while(std::cin >> W) {
        std::vector<int> radii;
        int radius;
        while(std::cin >> radius) {
            radii.push_back(radius);
            if(std::cin.peek() == '\n') {
                break;
            }
        }
        if(arrangeCakes(W, radii)) {
            std::cout << "OK\n";
        } else {
            std::cout << "NA\n";
        }
    }
    return 0;
}