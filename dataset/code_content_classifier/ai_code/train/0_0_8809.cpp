#include <iostream>

using namespace std;

int main() {
    int r, D, x_2000;
    cin >> r >> D >> x_2000;

    for(int i = 1; i <= 10; i++) {
        int x_next = r*x_2000 - D;
        cout << x_next << endl;
        x_2000 = x_next;
    }

    return 0;
}