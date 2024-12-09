#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    long long a_I, a_O, a_T, a_J, a_L, a_S, a_Z;
    cin >> a_I >> a_O >> a_T >> a_J >> a_L >> a_S >> a_Z;

    long long maxK = 0;

    // Find the maximum possible value of K by trying all possible combinations
    for (int k = 0; k <= a_T; k++) {
        // Calculate the maximum number of rectangles that can be formed with k T-tetrominos
        long long num_rectangles = k / 2;
        
        // Update maxK if a rectangle can be formed using the current combination of tetrominos
        maxK = max(maxK, num_rectangles);
    }

    cout << maxK * 2 << endl;

    return 0;
}