#include <iostream>

using namespace std;

int main() {
    int X, Y;
    cin >> X >> Y;

    // Calculate the total cost with the special ticket
    int cost = X + Y/2;

    cout << cost << endl;

    return 0;
}