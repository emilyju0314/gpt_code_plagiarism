#include <iostream>

int main() {
    int n;
    std::cin >> n;

    // Array to store the colors
    char colors[] = {'R', 'O', 'Y', 'G', 'B', 'I', 'V'};
    
    // Printing the required colors
    for (int i = 0; i < n; i++) {
        std::cout << colors[i % 7];
    }
    std::cout << std::endl;

    return 0;
}