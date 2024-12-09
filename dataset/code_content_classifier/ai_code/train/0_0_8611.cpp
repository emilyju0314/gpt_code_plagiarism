#include <iostream>
using namespace std;

int main() {
    int HPY, ATKY, DEFY;
    int HPM, ATKM, DEFM;
    int h, a, d;

    cin >> HPY >> ATKY >> DEFY;
    cin >> HPM >> ATKM >> DEFM;
    cin >> h >> a >> d;

    int minBitcoins = INT_MAX;
    for (int i = 0; i <= 100; i++) {
        for (int j = 0; j <= 100; j++) {
            for (int k = 0; k <= 100; k++) {
                if (ATKY + j > DEFM) {
                    int curBitcoins = i*h + j*a + k*d;
                    if (curBitcoins < minBitcoins) {
                        if (max(0, ATKM - DEFY) == 0) {
                            if (max(0, ATKY - DEFM) > 0) {
                                minBitcoins = curBitcoins;
                            }
                        } else {
                            int turnsNeeded = (HPM + max(0, ATKY - DEFM) - 1) / max(0, ATKM - DEFY);
                            int YangTurnsToDie = (HPY + max(0, ATKM - DEFY) - 1) / max(0, ATKY - DEFM);
                            if (turnsNeeded <= YangTurnsToDie) {
                                minBitcoins = min(minBitcoins, curBitcoins);
                            }
                        }
                    }
                }
            }
        }
    }

    cout << minBitcoins << endl;

    return 0;
}