#include <iostream>

int main() {
    int N, A;
    std::cin >> N >> A;
    
    int total_squares = N * N;
    int white_squares = A;
    int black_squares = total_squares - white_squares;
    
    std::cout << black_squares << std::endl;
    
    return 0;
}