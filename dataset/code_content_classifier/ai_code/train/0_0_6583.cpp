#include <iostream>

using namespace std;

int main() {
    int m, n;
    cin >> m >> n;

    int left = 1, right = m;

    while (true) {
        int mid = (left + right) / 2;
        cout << mid << endl;
        fflush(stdout);
        int response;
        cin >> response;

        if (response == 0) {
            exit(0);
        } else if (response == 1) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return 0;
}