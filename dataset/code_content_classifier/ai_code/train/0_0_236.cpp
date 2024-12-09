#include <iostream>

int main() {
    int rectangles = 0;
    int diamonds = 0;
    
    while(true) {
        int a, b, c;
        char comma;
        
        std::cin >> a >> comma >> b >> comma >> c;
        
        if(std::cin.fail()) {
            break;
        }
        
        if(a == b) {
            if(a*a + b*b == c*c) {
                rectangles++;
            } else {
                diamonds++;
            }
        } else {
            if(a*a + b*b == c*c) {
                rectangles++;
            }
        }
    }
    
    std::cout << rectangles << std::endl;
    std::cout << diamonds << std::endl;
    
    return 0;
}