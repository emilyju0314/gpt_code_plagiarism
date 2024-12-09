#include <iostream>

using namespace std;

int main() {
    int N;
    cin >> N;

    int colors[N];
    for (int i = 0; i < N; i++) {
        cin >> colors[i];
    }

    int spells = 0;
    for (int i = 1; i < N; i++) {
        if (colors[i] == colors[i-1]) {
            spells++;
            colors[i] = 0; // Change the color to a different color
        }
    }

    cout << spells << endl;

    return 0;
}