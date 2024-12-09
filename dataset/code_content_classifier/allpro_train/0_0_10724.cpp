#include <iostream>
#include <string>
#include <cmath>

struct Color {
    std::string name;
    int red;
    int green;
    int blue;
};

int main() {
    Color colors[] = {
        {"black", 0, 0, 0},
        {"blue", 0, 0, 255},
        {"lime", 0, 255, 0},
        {"aqua", 0, 255, 255},
        {"red", 255, 0, 0},
        {"fuchsia", 255, 0, 255},
        {"yellow", 255, 255, 0},
        {"white", 255, 255, 255}
    };
    
    std::string colorNum;
    
    while (std::cin >> colorNum && colorNum != "0") {
        if (colorNum[0] == '#') {
            colorNum = colorNum.substr(1); // Remove the # character
        }
        
        int red = std::stoi(colorNum.substr(0, 2), 0, 16);
        int green = std::stoi(colorNum.substr(2, 2), 0, 16);
        int blue = std::stoi(colorNum.substr(4, 2), 0, 16);
        
        int smallestDk = INT_MAX;
        std::string closestColor;
        
        for (const Color& c : colors) {
            int dk = pow(red - c.red, 2) + pow(green - c.green, 2) + pow(blue - c.blue, 2);
            if (dk < smallestDk) {
                smallestDk = dk;
                closestColor = c.name;
            }
        }
        
        std::cout << closestColor << std::endl;
    }
    
    return 0;
}