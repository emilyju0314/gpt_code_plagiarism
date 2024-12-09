#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>

using namespace std;

int main() {
    int n;
    cin >> n;

    int color = 1; // Alice's chosen color

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            // Bob chooses a color different from Alice's
            int b = (color + 1) > 3 ? 1 : color + 1;

            cout << b << " " << i << " " << j << endl;
            cout.flush();

            // Change color for Alice's next turn
            color = (color % 3) + 1;
        }
    }

    return 0;
}