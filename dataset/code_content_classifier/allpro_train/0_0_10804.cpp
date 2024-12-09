#include <iostream>
#include <vector>
#include <bitset>

bool isValidPermutation(int N, int A, int B, std::vector<int>& permutation) {
    for (int i = 0; i < (1 << N) - 1; i++) {
        int diff = permutation[i] ^ permutation[i+1];
        if (std::bitset<17>(diff).count() != 1) {
            return false;
        }
    }
    return true;
}

int main() {
    int N, A, B;
    std::cin >> N >> A >> B;

    std::vector<int> permutation((1 << N));
    for (int i = 0; i < (1 << N); i++) {
        permutation[i] = i;
    }

    permutation[0] = A;
    permutation[(1 << N) - 1] = B;

    do {
        if (isValidPermutation(N, A, B, permutation)) {
            std::cout << "YES" << std::endl;
            for (int i = 0; i < (1 << N); i++) {
                std::cout << permutation[i] << " ";
            }
            std::cout << std::endl;
            return 0;
        }
    } while (std::next_permutation(permutation.begin() + 1, permutation.end() - 1));

    std::cout << "NO" << std::endl;

    return 0;
}