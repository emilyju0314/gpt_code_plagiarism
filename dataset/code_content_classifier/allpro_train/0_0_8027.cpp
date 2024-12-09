#include <iostream>

int main() {
    int N, count = 0;
    std::cin >> N;
    int a[N];
    
    for(int i = 0; i < N; i++) {
        std::cin >> a[i];
        if(a[i] % 2 == 1 && i % 2 == 0) {
            count++;
        }
    }
    
    std::cout << count << std::endl;
    
    return 0;
}