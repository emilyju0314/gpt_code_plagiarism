#include <iostream>
#include <vector>

int main() {
    std::vector<int> input(7);
    
    for(int i = 0; i < 7; i++) {
        std::cin >> input[i];
    }
    
    std::vector<int> output(5);
    
    output[0] = input[0] - input[3];
    output[1] = input[1] - input[4];
    output[2] = input[2] - input[5];
    
    output[3] = output[0] + output[1] + output[2];
    output[4] = input[6] - output[3];
    
    for(int i = 0; i < 5; i++) {
        std::cout << output[i] << " ";
    }
    
    return 0;
}