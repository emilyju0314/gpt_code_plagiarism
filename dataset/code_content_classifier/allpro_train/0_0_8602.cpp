#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    int max_joy = -1;

    for (int i = 0; i < n; i++) {
        int fi, ti;
        cin >> fi >> ti;

        int joy = (ti > k) ? fi - (ti - k) : fi;

        if (joy > max_joy) {
            max_joy = joy;
        }
    }

    cout << max_joy << endl;

    return 0;
}