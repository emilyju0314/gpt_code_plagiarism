#include <iostream>

using namespace std;

int main() {
    int n, m, a, b;
    cin >> n >> m >> a >> b;

    int totalRows = n / m;
    int lastRowStart = totalRows * m + 1;
    int firstSelection = (a - 1) / m + 1;
    int lastSelection = (b - 1) / m + 1;

    int ans = lastSelection - firstSelection + 1;

    if (totalRows > 1 && (a <= lastRowStart && b >= lastRowStart)) {
        ans++;
    }

    cout << ans << endl;

    return 0;
}