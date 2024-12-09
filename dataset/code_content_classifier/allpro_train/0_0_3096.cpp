#include <iostream>
#include <string>

int main() {
    std::string s;
    std::cin >> s;
    
    int price = 700; // base price of the ramen
    
    // iterate through the string to calculate the total price based on the presence of toppings
    for(int i = 0; i < 3; i++) {
        if(s[i] == 'o') {
            price += 100; // add 100 yen for each topping
        }
    }
    
    std::cout << price << std::endl;
    
    return 0;
}