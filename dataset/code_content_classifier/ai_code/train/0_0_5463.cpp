#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    int head_x = -1, head_y = -1, tail_x = -1, tail_y = -1;

    // Find the head cell
    for (int x = 1; x <= n; x++) {
        cout << "? " << x << " 1 " << x << " " << n << endl;
        cout.flush();

        int ans;
        cin >> ans;

        if (ans == 1) {
            head_x = x;
            break;
        }
    }

    // Find the tail cell
    for (int x = 1; x <= n; x++) {
        cout << "? " << x << " 1 " << x << " " << n << endl;
        cout.flush();

        int ans;
        cin >> ans;

        if (ans == 1 && head_x != x) {
            tail_x = x;
            break;
        }
    }

    // Find the head y coordinate
    for (int y = 1; y <= n; y++) {
        cout << "? " << head_x << " " << y << " " << head_x << " " << y << endl;
        cout.flush();

        int ans;
        cin >> ans;

        if (ans > 0) {
            head_y = y;
            break;
        }
    }

    // Find the tail y coordinate
    for (int y = 1; y <= n; y++) {
        cout << "? " << tail_x << " " << y << " " << tail_x << " " << y << endl;
        cout.flush();

        int ans;
        cin >> ans;

        if (ans > 0) {
            tail_y = y;
            break;
        }
    }

    // Output the results
    cout << "! " << head_x << " " << head_y << " " << tail_x << " " << tail_y << endl;

    return 0;
}