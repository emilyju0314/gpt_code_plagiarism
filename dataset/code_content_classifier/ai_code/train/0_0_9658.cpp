#include <iostream>
#include <string>

using namespace std;

int main() {
    int xp, yp, xv, yv;
    cin >> xp >> yp >> xv >> yv;

    // Calculate the minimum number of turns for each player to reach (0, 0)
    int turns_polycarp = max(xp, yp);
    int turns_vasiliy = min(xv, min(yv, abs(xv - xp + yv - yp)));

    // Determine the winner based on the number of turns
    if (turns_polycarp <= turns_vasiliy) {
        cout << "Polycarp" << endl;
    } else {
        cout << "Vasiliy" << endl;
    }

    return 0;
}