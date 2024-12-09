#include <iostream>
#include <string>

using namespace std;

int main() {
    string r, a;

    while (true) {
        cin >> r >> a;
        if (r == "0" && a == "0") {
            break;
        }

        int hits = 0;
        int blows = 0;

        // Check for hits
        for (int i = 0; i < 4; i++) {
            if (r[i] == a[i]) {
                hits++;
            }
        }

        // Check for blows
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                if (i != j && r[i] == a[j]) {
                    blows++;
                }
            }
        }

        cout << hits << " " << blows << endl;
    }

    return 0;
}