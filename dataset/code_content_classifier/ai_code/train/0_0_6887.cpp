#include <iostream>

using namespace std;

int main() {
    int n, c0, c1;
    cin >> n >> c0 >> c1;

    // To minimize the total cost, we need to assign the longest binary representation to the letter with the highest frequency
    // Let's say the two most frequent letters are a and b, with frequencies x and y (x >= y)
    // then the binary representation of a should be '0' concatenated y times followed by '1', and for b it should be '1' concatenated y times followed by '0'

    long long cost = 0;
    if (c0 <= c1) {
        // 0 is cheaper, so we use it to encode letters with lower frequency
        cost = (long long)n * c0 + min(c0, c1); // if c0 == c1, it doesn't matter which one we choose to clean up the single bit
    } else {
        // 1 is cheaper, so we use it to encode letters with lower frequency
        cost = (long long)n * c1 + min(c0, c1); // if c0 == c1, it doesn't matter which one we choose to clean up the single bit
    }

    cout << cost << endl;

    return 0;
}