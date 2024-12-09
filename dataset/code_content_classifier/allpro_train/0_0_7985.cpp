#include <iostream>

using namespace std;

long long getOutOfBed(long long a, long long b, long long c, long long d) {
    if (b >= a) {
        return b;
    }

    if (c <= d) {
        return -1;
    }

    long long time = b;
    a -= b;
    long long numResets = (a + c - 1) / c;
    time += numResets * c;

    return time;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        long long a, b, c, d;
        cin >> a >> b >> c >> d;

        cout << getOutOfBed(a, b, c, d) << endl;
    }

    return 0;
}