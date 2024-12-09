#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int N, V, X, Y;
    cin >> N >> V >> X >> Y;

    for (int i = 0; i < N; i++) {
        int L, B, R, T;
        cin >> L >> B >> R >> T;

        // Check if the pig is within the obstacle
        if (X >= L && X <= R && Y >= B && Y <= T) {
            cout << "No" << endl;
            return 0;
        }
    }

    // Calculate the time it takes for the white bird to reach the pig
    double time = (double)X / V;

    // Calculate the vertical position of the white bird at the calculated time
    double height = (V * time) - (0.5 * 9.8 * time * time);

    // Check if the vertical position is above the pig
    if (height >= Y) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}