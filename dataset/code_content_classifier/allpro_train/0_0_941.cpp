#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;

    int koshiroWins = 0;
    int ukikoWins = 0;

    for (int i = 0; i < N; i++) {
        int w, b;
        cin >> w >> b;

        // If the number of black stones is greater than the number of white stones with a difference of more than 1, Ukiko wins
        if (b > w + 1) {
            ukikoWins++;
        }
        // If the number of white stones is greater than or equal to the number of black stones, Koshiro wins
        else {
            koshiroWins++;
        }
    }

    // Output 0 if Koshiro wins and 1 if Ukiko wins
    if (koshiroWins > ukikoWins) {
        cout << 0 << endl;
    } else {
        cout << 1 << endl;
    }

    return 0;
}