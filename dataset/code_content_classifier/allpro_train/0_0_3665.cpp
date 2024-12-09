#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

// Function to check if a number is prime
bool isPrime(int n) {
    if (n <= 1) {
        return false;
    }
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

// Function to generate all possible matrices for a given prime number
int generateMatrices(int prime) {
    int count = 0;
    std::string prime_str = std::to_string(prime);

    do {
        std::string row1, row2, row3;
        row1 = prime_str;
        row2 = std::to_string(std::stoi(row1) * 2);
        row3 = std::to_string(std::stoi(row2) * 3);

        std::unordered_map<char, char> mapping;
        bool valid = true;

        for (int i = 0; i < row1.length(); i++) {
            char c = row1[i];
            if (mapping.find(c) == mapping.end()) {
                mapping[c] = row3[i];
            } else {
                if (mapping[c] != row3[i]) {
                    valid = false;
                    break;
                }
            }
        }

        if (valid) {
            count++;
        }
    } while (std::next_permutation(prime_str.begin(), prime_str.end()));

    return count;
}

int main() {
    int t;
    std::cin >> t;
    std::vector<int> primes(t);

    for (int i = 0; i < t; i++) {
        std::cin >> primes[i];
    }

    for (int i = 0; i < t; i++) {
        int count = generateMatrices(primes[i]);
        std::cout << count << std::endl;
    }

    return 0;
}