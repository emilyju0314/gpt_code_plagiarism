#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main() {
    int n;
    cin >> n;

    string a, b;
    cin >> a >> b;

    int cnt = 0;
    for(int i = 0; i < n; i++) {
        if(a[i] == b[i]) {
            cnt++;
        }
    }

    double ans = (1.0 * cnt * (2*n - cnt)) / (1.0 * n * n);

    cout << fixed << setprecision(9) << ans << endl;

    return 0;
}