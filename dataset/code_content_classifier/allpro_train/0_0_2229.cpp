#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1000000007;

int main() {
    int N;
    cin >> N;

    // Total number of sequences of length N with digits from 0 to 9
    long long total_sequences = 1;
    for (int i = 0; i < N; i++) {
        total_sequences = (total_sequences * 10) % MOD;
    }

    // Number of sequences where A_i != 0 for all i
    long long sequences_without_zero = 1;
    for (int i = 0; i < N; i++) {
        sequences_without_zero = (sequences_without_zero * 9) % MOD;
    }

    // Number of sequences where A_i != 9 for all i
    long long sequences_without_nine = 1;
    for (int i = 0; i < N; i++) {
        sequences_without_nine = (sequences_without_nine * 9) % MOD;
    }

    // Number of sequences where both A_i != 0 and A_i != 9 for all i
    long long sequences_without_zero_and_nine = 1;
    for (int i = 0; i < N; i++) {
        sequences_without_zero_and_nine = (sequences_without_zero_and_nine * 8) % MOD;
    }

    // Subtract the invalid sequences from the total
    long long valid_sequences = (total_sequences - sequences_without_zero - sequences_without_nine + sequences_without_zero_and_nine + MOD) % MOD;

    cout << valid_sequences << endl;

    return 0;
}