#include <iostream>
using namespace std;

int main() {
    long long M, rD, rR, cD, cR;
    cin >> M >> rD >> rR >> cD >> cR;

    long long maxReturn = 0;

    for(long long x = 0; x <= M; x++) {
        long long moneyD = (rD * x) / 100;
        long long moneyR = (rR * (M - x)) / 100;

        if(moneyD >= cD && moneyR >= cR) {
            long long remainingD = moneyD - cD;
            long long remainingR = moneyR - cR;

            long long returnYen = ((remainingD * 100) / rD) + ((remainingR * 100) / rR);
            maxReturn = max(maxReturn, returnYen);
        }
    }

    if(maxReturn == 0) {
        cout << -1 << endl;
    } else {
        cout << maxReturn << endl;
    }

    return 0;
}