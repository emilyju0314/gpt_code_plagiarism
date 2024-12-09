#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    int chest = 0, biceps = 0, back = 0;
    for (int i = 0; i < n; i++) {
        int exercises;
        cin >> exercises;

        if (i % 3 == 0) {
            chest += exercises;
        } else if (i % 3 == 1) {
            biceps += exercises;
        } else {
            back += exercises;
        }
    }

    if (chest >= biceps && chest >= back) {
        cout << "chest" << endl;
    } else if (biceps >= chest && biceps >= back) {
        cout << "biceps" << endl;
    } else {
        cout << "back" << endl;
    }

    return 0;
}