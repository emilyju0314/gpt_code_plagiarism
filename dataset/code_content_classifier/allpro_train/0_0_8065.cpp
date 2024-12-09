#include <iostream>
#include <cmath>

int main() {
    int a, b, x1, y1, x2, y2;
    std::cin >> a >> b >> x1 >> y1 >> x2 >> y2;
    
    int badCells = 0;
    
    while (x1 != x2 || y1 != y2) {
        int diffX = x2 - x1;
        int diffY = y2 - y1;
        
        int stepsX = abs(diffX) / 2;
        int stepsY = abs(diffY) / 2;
        
        if ((abs(x1 + y1) % (2 * a) == 0 && stepsX > 0) || (abs(x1 - y1) % (2 * b) == 0 && stepsY > 0)) {
            badCells++;
        }
        
        if (stepsX == 0 || stepsY == 0) {
            badCells += abs(stepsX + stepsY);
            break;
        }
        
        x1 += stepsX * (diffX > 0 ? 1 : -1);
        y1 += stepsY * (diffY > 0 ? 1 : -1);
        badCells++;
    }
    
    std::cout << badCells << std::endl;
    
    return 0;
}