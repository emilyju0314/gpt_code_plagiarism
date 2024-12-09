#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, a, b;
    cin >> n >> a >> b;

    vector<int> clients(n);
    for (int i = 0; i < n; i++) {
        cin >> clients[i];
    }

    int denied = 0;
    int oneSeater = a;
    int twoSeater = b;

    for (int i = 0; i < n; i++) {
        if (clients[i] == 1) {
            if (oneSeater > 0) {
                oneSeater--;
            } else if (twoSeater > 0) {
                twoSeater--;
            } else {
                denied++;
            }
        } else {
            if (twoSeater > 0) {
                twoSeater--;
            } else {
                denied += 2;
            }
        }
    }

    cout << denied << endl;

    return 0;
}