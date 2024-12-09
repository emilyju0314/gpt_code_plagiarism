#include <iostream>

using namespace std;

int main() {
    int T;
    cin >> T;

    for (int i = 0; i < T; i++) {
        int str, intell, exp;
        cin >> str >> intell >> exp;

        int min_points = min(str, intell);
        int max_points = max(str, intell);

        int available_points = exp;
        int count = 0;

        for (int j = 1; j <= exp; j++) {
            // If the increased points are still valid
            if (min_points + j < max_points) {
                count++;
            }
        }

        cout << count << endl;
    }

    return 0;
}