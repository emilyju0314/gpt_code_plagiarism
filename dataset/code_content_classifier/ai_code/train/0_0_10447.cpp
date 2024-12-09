#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main() {
    int n;
    string f;
    cin >> n >> f;

    int total_ways = pow(2, n);
    int count[3] = {0};

    for (int i = 0; i < total_ways; i++) {
        int a = 0, b = 0, c = 0;

        int mask = 1;
        for (int j = 0; j < n; j++) {
            if ((i & mask) != 0) {
                if (f[j] == '0') {
                    a++;
                } else {
                    c++;
                }
            } else {
                if (f[j] == '0') {
                    b++;
                } else {
                    a++;
                }
            }
            mask <<= 1;
        }

        if (a >= 2) {
            count[0]++;
        }
        if (b >= 2) {
            count[1]++;
        }
        if (c >= 2) {
            count[2]++;
        }
    }

    int result = (count[0] + count[1] + count[2]) % 1000000007;
    cout << (result * total_ways) % 1000000007 << endl;

    return 0;
}