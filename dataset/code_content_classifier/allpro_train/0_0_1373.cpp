#include <iostream>
using namespace std;

int main() {
    int X, t;
    cin >> X >> t;

    int remaining_sand = max(0, X - t);
    cout << remaining_sand << endl;

    return 0;
}