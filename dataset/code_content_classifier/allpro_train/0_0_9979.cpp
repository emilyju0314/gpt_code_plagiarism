#include <iostream>
#include <vector>
#define MOD 998244353

int n;
std::vector<int> freq(100001, 0);

void generate_sequences(int pos, int last_val) {
    if (pos == n) {
        for (int i = 1; i <= n; i++) {
            freq[i]++;
        }
        return;
    }
    
    for (int i = 1; i <= last_val + 1; i++) {
        generate_sequences(pos + 1, std::max(last_val, i));
    }
}

int main() {
    std::cin >> n;

    generate_sequences(0, 0);

    for (int i = 1; i <= n; i++) {
        std::cout << freq[i] % MOD << " ";
    }

    return 0;
}