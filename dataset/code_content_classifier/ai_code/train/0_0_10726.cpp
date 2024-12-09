#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    int count = 0;
    for (int i = 0; i < n; i++) {
        int area;
        cin >> area;

        bool possible = false;
        for (int x = 1; x*x <= area; x++) {
            if (area % x == 0) {
                int y = area / x - x;
                if (y > 0 && (2*x*y + x + y) == area) {
                    possible = true;
                    break;
                }
            }
        }

        if (!possible) {
            count++;
        }
    }

    cout << count << endl;

    return 0;
}