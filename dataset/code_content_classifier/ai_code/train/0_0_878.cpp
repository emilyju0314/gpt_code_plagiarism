#include <iostream>
#include <vector>

using namespace std;

int main() {
    int q;
    cin >> q;

    vector<long long> prefixSum(10);
    prefixSum[1] = 1; // initialize the first block
    for (int i = 2; i <= 9; i++) {
        prefixSum[i] = i + prefixSum[i - 1]; // calculate the prefix sum for each block
    }

    while (q--) {
        long long k;
        cin >> k;

        int blockNum = 0;
        while (k > prefixSum[blockNum + 1]) {
            blockNum++;
        }

        k -= prefixSum[blockNum]; // adjust the position within the block
        cout << to_string(k)[k - 1] << endl; // print the digit at position k
    }

    return 0;
}