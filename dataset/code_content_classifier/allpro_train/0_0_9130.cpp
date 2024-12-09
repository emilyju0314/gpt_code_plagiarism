#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    int m, n;
    cin >> m >> n;

    double total = 0.0;
    for(int i = 1; i <= m; i++) {
        double prob = (double)i / m;
        total += prob * (1 - pow(1 - prob, n));
    }

    cout << fixed << setprecision(12) << total << endl;

    return 0;
}