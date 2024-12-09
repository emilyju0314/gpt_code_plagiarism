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

        long long ans = squares + cubes - 1 - (squares - 1) / 2 - (cubes - 1) / 2 - (squares + cubes - 2) / 2;
        
        cout << ans << endl;
    }

    return 0;
}