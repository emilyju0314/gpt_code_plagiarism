#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        long long n;
        cin >> n;

        long long squares = sqrt(n);
        long long cubes = cbrt(n);
        long long both = pow(sqrt(n), 6);

        long long result = squares + cubes - both;

        cout << result << endl;
    }

    return 0;
}