#include <iostream>

int main() {
    long long N, A, B;
    std::cin >> N >> A >> B;

    long long blueCount = (N / (A + B)) * A;
    long long remainder = N % (A + B);
    
    if(remainder >= A){
        blueCount += A;
    } else {
        blueCount += remainder;
    }

    std::cout << blueCount << std::endl;

    return 0;
}