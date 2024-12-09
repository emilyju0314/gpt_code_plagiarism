#include <iostream>
#include <vector>

using namespace std;

// Function to find the n-th element of the sequence
long long findNthElement(long long n) {
    // Calculate the position of the most significant bit in n
    long long msbPos = 0;
    long long temp = n;
    while (temp > 0) {
        msbPos++;
        temp >>= 1;
    }

    // Calculate the value of the n-th element based on the position of the most significant bit
    return (1ll << msbPos) - 1ll;
}

int main() {
    int t;
    cin >> t;

    // Vector to store the input values for t test cases
    vector<long long> testCases(t);

    // Read input values for t test cases
    for (int i = 0; i < t; i++) {
        cin >> testCases[i];
    }

    // Process each test case and output the result
    for (int i = 0; i < t; i++) {
        long long result = findNthElement(testCases[i]);
        cout << result << endl;
    }

    return 0;
}