#include <iostream>
#include <algorithm>

int main() {
    int pasta1, pasta2, pasta3, juice1, juice2;
    std::cin >> pasta1 >> pasta2 >> pasta3 >> juice1 >> juice2;
    
    // Find the minimum price of the set menu
    int price1 = pasta1 + juice1 - 50;
    int price2 = pasta1 + juice2 - 50;
    int price3 = pasta2 + juice1 - 50;
    int price4 = pasta2 + juice2 - 50;
    int price5 = pasta3 + juice1 - 50;
    int price6 = pasta3 + juice2 - 50;
    
    int min_price = std::min({price1, price2, price3, price4, price5, price6});
    
    std::cout << min_price << std::endl;
    
    return 0;
}