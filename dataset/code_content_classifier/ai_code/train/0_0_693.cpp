#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    int x = 0, y = 0;

    for (int i = 0; i < n; i++) {
        cout << x << " " << y << endl;
        x++;
        y++;
    }

    return 0;
}