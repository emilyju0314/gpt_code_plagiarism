#include <iostream>
using namespace std;

int main() {
    int a, x, y;
    cin >> a >> x >> y;

    int row = y / a;
    int numBlocks;
    if (row % 2 == 0) {
        numBlocks = 1 + (x + a) / (2 * a);
    } else {
        numBlocks = 1 + x / (2 * a);
    }

    if (y % a != 0 || (x % a == 0 && y % (2 * a) == 0) || (x % a == a / 2 && y % (2 * a) == a) || x % a == a) {
        cout << -1 << endl;
    } else {
        cout << (row * ((row + 1) / 2) + numBlocks) << endl;
    }

    return 0;
}