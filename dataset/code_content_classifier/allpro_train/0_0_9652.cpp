#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    int penalty = n + m - 1 + (n-1)*(m-1); // Calculate the minimum penalty

    cout << penalty << endl;

    int x = 1, y = 1;
    for (int i = 0; i < k; i++) {
        int dest_x = (i % n) + 1;
        int dest_y = (i / n) + 1;

        cout << "(1,1) ";
        for (int j = x; j < dest_x; j++) {
            x = j;
            cout << "(" << j << "," << y << ") ";
        }
        for (int j = y; j < dest_y; j++) {
            y = j;
            cout << "(" << x << "," << j << ") ";
        }

        cout << "(" << dest_x << "," << dest_y << ")" << endl;
    }

    return 0;
}