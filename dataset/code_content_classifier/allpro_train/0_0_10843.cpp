#include <iostream>
using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;

    cout << "First" << endl;
    cout << 2 << endl;
    cout.flush();

    int y;
    cin >> y;
    if (y == 2) {
        cout << 1 << endl;
        cout.flush();
    } else {
        cout << 2 << endl;
        cout.flush();
    }

    return 0;
}