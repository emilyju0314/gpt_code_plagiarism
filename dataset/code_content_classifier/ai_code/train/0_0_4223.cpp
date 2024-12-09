#include <iostream>

using namespace std;

int main() {
    int A, B, T;
    cin >> A >> B >> T;

    int total = 0;
    int time = 0;
    int count = 1;

    while (time <= T + 0.5) {
        time = count * A;
        total += B;
        count++;
    }

    cout << total << endl;

    return 0;
}