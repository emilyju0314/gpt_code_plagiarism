#include <iostream>

using namespace std;

int main() {
    int k;
    cin >> k;

    while (k--) {
        int n, x, t;
        cin >> n >> x >> t;

        long long result = 0;

        // Calculate the minimum of n-1 and t/x
        long long minVal = min((long long)n-1, t/x);

        // Dissatisfaction of each person is min(n-1, t/x)
        // So total dissatisfaction is the sum of arithmetic progression
        result = minVal * (n - minVal);

        cout << result << endl;
    }

    return 0;
}