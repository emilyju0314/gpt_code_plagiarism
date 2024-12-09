#include <iostream>
#include <vector>

std::string convertToLetters(int a, int b, int c, int d, int e) {
    std::string result = "";
    
    int sum = a + b + c;
    
    switch(sum) {
        case 0:
            result += 'a';
            break;
        case 1:
            result += 'b';
            break;
        case 2:
            result += 'c';
            break;
    }
    
    sum = d + e;
    
    switch(sum) {
        case 0:
            result += 'a';
            break;
        case 1:
            result += 'b';
            break;
        case 2:
            result += 'c';
            break;
    }
    
    return result;
}

int main() {
    int N;
    std::cin >> N;
    
    std::vector<std::vector<int>> inputs(N, std::vector<int>(5));
    
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < 5; j++) {
            std::cin >> inputs[i][j];
        }
    }
    
    for(int i = 0; i < N; i++) {
        int a = inputs[i][0];
        int b = inputs[i][1];
        int c = inputs[i][2];
        int d = inputs[i][3];
        int e = inputs[i][4];
        
        std::cout << convertToLetters(a, b, c, d, e);
    }
    
    std::cout << std::endl;
    
    return 0;
}