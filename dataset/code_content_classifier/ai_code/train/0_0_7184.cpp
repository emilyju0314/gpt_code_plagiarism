#include <iostream>
#include <string>
using namespace std;

int main() {
    int K;
    cin >> K;

    string isonoPoses[K], nakajimaPoses[K];
    for (int i = 0; i < K; i++) {
        cin >> isonoPoses[i];
    }
    for (int i = 0; i < K; i++) {
        cin >> nakajimaPoses[i];
    }

    int isonoAttackPower = 0, nakajimaAttackPower = 0;
    string result = "Hikiwake-kun";

    for (int i = 0; i < K; i++) {
        if (isonoPoses[i] == "tameru") {
            isonoAttackPower = min(isonoAttackPower + 1, 5);
            if (nakajimaPoses[i] == "kougekida" && nakajimaAttackPower > 0) {
                result = "Nakajima-kun";
                break;
            }
        } else if (isonoPoses[i] == "kougekida") {
            if (isonoAttackPower == 0) {
                result = "Nakajima-kun";
                break;
            } else {
                if (nakajimaPoses[i] == "kougekida" && nakajimaAttackPower > 0) {
                    if (isonoAttackPower > nakajimaAttackPower) {
                        result = "Isono-kun";
                        break;
                    } else if (isonoAttackPower < nakajimaAttackPower) {
                        result = "Nakajima-kun";
                        break;
                    }
                } else {
                    nakajimaAttackPower = min(nakajimaAttackPower + 1, 5);
                }
            }
        }
    }

    cout << result << endl;

    return 0;
}