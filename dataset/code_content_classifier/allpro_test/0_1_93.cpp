#include <iostream>
using namespace std;

long long minHours(long long n, long long k) {
    if(n <= k) {
        return 1;
    } else {
        long long minHours = (n + k - 1) / k;
        return minHours;
    }
}

int main() {
    int t;
    cin >> t;

    while(t--) {
        long long n, k;
        cin >> n >> k;

        cout << minHours(n, k) << endl;
    }

    return 0;
}