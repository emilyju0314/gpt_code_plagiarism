#include <iostream>
#include <vector>
#include <cmath>

int main() {
    int t;
    std::cin >> t;

    std::vector<long long> squares, cubes;

    for(long long i = 1; i <= 10000; i++) {
        squares.push_back(i*i);
        cubes.push_back(i*i*i);
    }

    while (t--) {
        long long n;
        std::cin >> n;

        long long count = 0;

        for(auto sq : squares) {
            if(sq <= n) {
                count++;
            } else {
                break;
            }
        }

        for(auto cu : cubes) {
            if(cu <= n) {
                count++;
            } else {
                break;
            }
        }

        std::cout << count << std::endl;
    }

    return 0;
}