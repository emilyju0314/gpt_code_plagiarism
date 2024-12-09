#include <iostream>

using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;

        int minTotalScore = (a + c >= 100) ? 100 : (a + c + 1);
        minTotalScore = max(minTotalScore, b + d + 1);

        cout << minTotalScore << endl;
    }

    return 0;
}