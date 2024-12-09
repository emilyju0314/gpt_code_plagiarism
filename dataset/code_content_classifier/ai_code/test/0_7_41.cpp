#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    int c = 2; // start with 2 colors
    while (c * (c - 1) / 2 < k) c++;

    cout << c << endl;

    int color = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            cout << color << " ";
            color++;
            if (color > c) color = 1;
        }
    }

    return 0;
}