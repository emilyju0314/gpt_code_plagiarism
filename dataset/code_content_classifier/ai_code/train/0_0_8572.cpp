#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    int A, B, P, Q, R;
    cin >> A >> B >> P >> Q >> R;

    double time = 0;
    double distanceE = 0;
    double distanceS = 0;

    while (true) {
        if (distanceE >= distanceS && distanceE <= distanceS + R * B) {
            break;
        }

        time += 1;
        distanceE += P;
        distanceS += Q;
    }

    double meetingTime = distanceE / (P + R);

    cout << fixed << setprecision(12) << meetingTime << endl;

    return 0;
}