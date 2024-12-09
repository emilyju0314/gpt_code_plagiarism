#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

int gcd(int a, int b) {
    if(b == 0) return a;
    return gcd(b, a % b);
}

int main() {
    int t;
    std::cin >> t;

    while(t--) {
        int n;
        std::cin >> n;

        std::vector<int> divisors;
        for(int i = 2; i <= sqrt(n); i++) {
            if(n % i == 0) {
                divisors.push_back(i);
                if(n / i != i) {
                    divisors.push_back(n / i);
                }
            }
        }

        std::sort(divisors.begin(), divisors.end());

        std::vector<int> result;
        result.push_back(divisors[0]);
        for(int i = 1; i < divisors.size(); i++) {
            if(gcd(result.back(), divisors[i]) == 1) {
                result.push_back(1);
            }
            result.push_back(divisors[i]);
        }

        std::cout << result[0];
        for(int i = 1; i < result.size(); i++) {
            std::cout << " " << result[i];
        }
        std::cout << std::endl;

        std::cout << result.size() - divisors.size() << std::endl;
    }

    return 0;
}