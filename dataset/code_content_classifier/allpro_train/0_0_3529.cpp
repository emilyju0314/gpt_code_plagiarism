#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int A, B, K;
    cin >> A >> B >> K;

    vector<int> factors;
    for (int i = 1; i <= min(A, B); i++) {
        if (A % i == 0 && B % i == 0) {
            factors.push_back(i);
        }
    }

    sort(factors.begin(), factors.end(), greater<int>());

    cout << factors[K-1] << endl;

    return 0;
}