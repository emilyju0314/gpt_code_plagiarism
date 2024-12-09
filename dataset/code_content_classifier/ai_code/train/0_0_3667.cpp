#include <iostream>
#include <cmath>
#include <string>

using namespace std;

int main() {
    int n;
    string a, b;
    cin >> n >> a >> b;

    int same = 0;
    for(int i = 0; i < n; i++) {
        if(a[i] == b[i]) {
            same++;
        }
    }

    double result = 0;
    for(int i = 0; i < n; i++) {
        result += 1.0 / n * (same + (a[i] == b[i] ? -1 : 0));
    }

    cout << fixed;
    cout.precision(9);
    cout << result << endl;

    return 0;
}