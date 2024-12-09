#include <iostream>
#include <string>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int a, b;
        cin >> a >> b;

        string mines;
        cin >> mines;

        int cost = 0;
        int segments = 0;
        bool inSegment = false;

        for (char mine : mines) {
            if (mine == '1') {
                if (!inSegment) {
                    cost += min(a, b);
                    inSegment = true;
                } else {
                    cost += a;
                }
            } else {
                inSegment = false;
            }
        }

        cout << cost << endl;
    }

    return 0;
}