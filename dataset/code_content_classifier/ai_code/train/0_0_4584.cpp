#include <iostream>

int main() {
    int x, y;
    std::string directions;
    
    std::cin >> x >> y;
    std::cin >> directions;
    
    for(char direction : directions) {
        if(direction == 'N') {
            y++;
        } else if(direction == 'S') {
            y--;
        } else if(direction == 'E') {
            x++;
        } else if(direction == 'W') {
            x--;
        }
    }
    
    std::cout << x << " " << y << std::endl;
    
    return 0;
}