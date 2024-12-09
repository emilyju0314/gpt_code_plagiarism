#include <iostream>
#include <string>

using namespace std;

int main() {
    long long n, m;
    cin >> n >> m;

    string x, y;
    cin >> x >> y;

    long long len_x = x.length();
    long long len_y = y.length();

    long long lcm = (n * m) / __gcd(n, m);

    string a = "", b = "";

    for (long long i = 0; i < lcm / len_x; i++) {
        a = a + x;
    }

    for (long long i = 0; i < lcm / len_y; i++) {
        b = b + y;
    }

    long long hamming_distance = 0;
    for (long long i = 0; i < lcm; i++) {
        hamming_distance += (a[i] != b[i]);
    }

    cout << hamming_distance << endl;

    return 0;
}