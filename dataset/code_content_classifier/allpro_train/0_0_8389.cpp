#include <iostream>
using namespace std;

int main() {
    int w;

    while (true) {
        cin >> w;
        if (w == -1) {
            break;
        }

        int lastMonthCharge = 4280;
        int basicCharge = 1150;
        int stage2Charge = 125;
        int stage3Charge = 140;
        int stage4Charge = 160;

        int totalCharge = 0;

        if (w <= 10) {
            totalCharge = basicCharge;
        } else if (w <= 20) {
            totalCharge = basicCharge + (w - 10) * stage2Charge;
        } else if (w <= 30) {
            totalCharge = basicCharge + 10 * stage2Charge + (w - 20) * stage3Charge;
        } else {
            totalCharge = basicCharge + 10 * stage2Charge + 10 * stage3Charge + (w - 30) * stage4Charge;
        }

        int savedCharge = lastMonthCharge - totalCharge;
        cout << savedCharge << endl;
    }

    return 0;
}