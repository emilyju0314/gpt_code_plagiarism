#include <iostream>

using namespace std;

int main() {
    int A, B;
    cin >> A >> B;

    int cost = 0;

    if (A >= 13) {
        cost = B;
    } else if (A >= 6) {
        cost = B / 2;
    }

    cout << cost << endl;

    return 0;
}