#include <iostream>

int main() {
    int N;
    std::cin >> N;
    
    long long sum = 0;
    for(int i = 1; i <= N; i++) {
        if(i % 3 == 0 && i % 5 == 0) {
            sum += i;
        } else if(i % 3 == 0) {
            sum += i;
        } else if(i % 5 == 0) {
            sum += i;
        }
    }
    
    std::cout << sum << std::endl;
    
    return 0;
}