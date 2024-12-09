#include <iostream>
using namespace std;

int findLastCard(int N, int A, int B, string D_A, string D_B) {
    int direction_A = (D_A == "left") ? -1 : 1;
    int direction_B = (D_B == "left") ? -1 : 1;

    int remaining = N;
    while (A != B) {
        if (A < B) {
            B = (B + direction_B) % remaining;
            direction_B = (direction_B == 1) ? -1 : 1;
            remaining--;
        } else {
            A = (A + direction_A) % remaining;
            direction_A = (direction_A == 1) ? -1 : 1;
            remaining--;
        }
    }

    return A;
}

int main() {
    int T;
    cin >> T;

    for (int i = 0; i < T; i++) {
        int N, A, B;
        string D_A, D_B;
        cin >> N >> A >> B >> D_A >> D_B;

        int result = findLastCard(N, A, B, D_A, D_B);
        cout << result << endl;
    }

    return 0;
}