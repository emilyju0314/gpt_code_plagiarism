#include <iostream>
#include <string>
#include <vector>
#include <cmath>

// Function to parse the input polynomial and store the coefficients
void parsePolynomial(std::string poly, std::vector<int>& coefficients) {
    int coeff = 0;
    int sign = 1;
    bool hasCoeff = false;
    
    for(char c : poly) {
        if(c == 'x') {
            if(hasCoeff) {
                coefficients.push_back(coeff * sign);
                coeff = 0;
                hasCoeff = false;
            }
        } else if(c == '^' || c == '+' || c == '-') {
            continue;
        } else if(c == '+') {
            sign = 1;
        } else if(c == '-') {
            sign = -1;
        } else {
            hasCoeff = true;
            coeff = coeff * 10 + (c - '0');
        }
    }
    
    if(hasCoeff) {
        coefficients.push_back(coeff * sign);
    }
}

// Function to factor the polynomial into linear expressions
void factorPolynomial(std::vector<int>& coefficients) {
    int n = coefficients.size() - 1;
    std::cout << "(";
    
    for(int i = 1; i <= n; i++) {
        int c = -coefficients[i];
        if(c < 0) {
            std::cout << "(x" << (c == -1 ? "" : "+") << -c << ")";
        } else {
            std::cout << "(x-" << c << ")";
        }
        
        if(i < n) {
            std::cout << ",";
        }
    }
    
    std::cout << ")" << std::endl;
}

int main() {
    std::string input;
    std::cin >> input;
    
    std::vector<int> coefficients;
    parsePolynomial(input, coefficients);
    
    factorPolynomial(coefficients);
    
    return 0;
}