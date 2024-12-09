#include <iostream>
using namespace std;

int main() {
    int A, B;
    cin >> A >> B;

    int h = 100, w = 100;
    cout << h << " " << w << endl;

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (i < h / 2) {
                cout << (j < w / 2 ? "#" : ".");
            } else {
                cout << (j < w / 2 ? "." : "#");
            }
        }
        cout << endl;
    }

    return 0;
}