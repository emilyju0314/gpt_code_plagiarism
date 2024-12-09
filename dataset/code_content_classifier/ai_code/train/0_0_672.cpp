#include <iostream>

int f(int N) {
    int count = 0;
    while (N > 2) {
        // Cut the rope at two positions
        int cut1 = N / 2;
        int cut2 = N - cut1;
        // Discard the longest and shortest lengths
        N = std::max(cut1, cut2);
        count++;
    }
    return count;
}

int main() {
    int X;
    std::cin >> X;
    
    int N = 2;
    while (f(N) < X) {
        N++;
    }
    
    std::cout << N << std::endl;
    
    return 0;
}