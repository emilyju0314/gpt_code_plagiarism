#include <iostream>
using namespace std;

int main() {
    int N, R;
    cin >> N >> R;

    int innerRating;
    if (N >= 10) {
        innerRating = R;
    } else {
        innerRating = R + 100 * (10 - N);
    }

    cout << innerRating << endl;

    return 0;
}