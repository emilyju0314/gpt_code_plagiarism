#include <iostream>
#include <vector>

using namespace std;

long long greatestCommonDivisor(long long a, long long b) {
    return b == 0 ? a : greatestCommonDivisor(b, a % b);
}

long long leastCommonMultiple(long long a, long long b) {
    return a * b / greatestCommonDivisor(a, b);
}

int main() {
    int k;
    cin >> k;

    vector<long long> powers(k);
    for (int i = 0; i < k; i++) {
        cin >> powers[i];
    }

    long long lcm = powers[0];
    for (int i = 1; i < k; i++) {
        lcm = leastCommonMultiple(lcm, powers[i]);
    }

    cout << lcm << endl;

    return 0;
}