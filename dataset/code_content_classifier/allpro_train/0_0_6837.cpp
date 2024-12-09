#include <iostream>

int main() {
    int S;
    std::cin >> S;

    int count = 0;
    for(int a = 1; a*a <= S; a++) {
        if(S % a == 0) {
            int b = S / a;
            count += b - a + 1;
        }
    }

    std::cout << count << std::endl;

    return 0;
}