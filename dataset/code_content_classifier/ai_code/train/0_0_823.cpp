#include <iostream>
#include <vector>

int convertToDecimal(std::vector<int>& num, int base) {
    int decimal = 0;
    for(int i = 0; i < num.size(); i++) {
        decimal = decimal*base + num[i];
    }
    return decimal;
}

int main() {
    int n, bx, m, by;
    std::cin >> n >> bx;

    std::vector<int> X(n);
    for(int i = 0; i < n; i++) {
        std::cin >> X[i];
    }

    std::cin >> m >> by;

    std::vector<int> Y(m);
    for(int i = 0; i < m; i++) {
        std::cin >> Y[i];
    }

    int decimalX = convertToDecimal(X, bx);
    int decimalY = convertToDecimal(Y, by);

    char result = ' ';
    if(decimalX < decimalY) {
        result = '<';
    } else if(decimalX > decimalY) {
        result = '>';
    } else {
        result = '=';
    }

    std::cout << result << std::endl;

    return 0;
}