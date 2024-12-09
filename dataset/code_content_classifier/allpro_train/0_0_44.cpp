#include <iostream>
using namespace std;

int rev(int n) {
    int reversed = 0;
    while (n > 0) {
        reversed = reversed * 10 + n % 10;
        n /= 10;
    }
    return reversed;
}

int main() {
    int maxx, maxy, w;
    cin >> maxx >> maxy >> w;

    int x = -1, y = -1;
    for (int i = 1; i <= maxx; i++) {
        for (int j = 1; j <= maxy; j++) {
            if (i * j * rev(i) * rev(j) >= w) {
                x = i;
                y = j;
                break;
            }
        }
        if (x != -1) {
            break;
        }
    }

    cout << x << " " << y << endl;

    return 0;
}