#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int n, a;
    cin >> n >> a;

    int min_diff = 180;
    int v1 = 1, v2 = 2, v3 = 3;

    for(int i = 1; i <= n; i++) {
        int angle1 = 180 * (i - 2) / n;
        int angle2 = 180 * i / n;

        int diff1 = abs(a - angle1);
        int diff2 = abs(a - angle2);

        if(diff1 < min_diff) {
            min_diff = diff1;
            v1 = i;
            v2 = i == n ? 1 : i + 1;
            v3 = i == 1 ? n : i - 1;
        }

        if(diff2 < min_diff) {
            min_diff = diff2;
            v1 = i;
            v2 = i == n ? 1 : i + 1;
            v3 = i == 1 ? n : i - 1;
        }
    }

    cout << v1 << " " << v2 << " " << v3 << endl;

    return 0;
}