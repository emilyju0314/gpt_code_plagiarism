#include <iostream>

int main() {
    int x1, y1, x2, y2;
    std::cin >> x1 >> y1 >> x2 >> y2;
  
    // Calculate the number of units to be filled
    int width = x2 - x1;
    int height = y2 - y1;
    int num_units = (width/2 + 1) * (height/2 + 1) + (width/2) * (height/2);
  
    std::cout << num_units << std::endl;
  
    return 0;
}