#include <iostream>
#include <string>

using namespace std;

int main() {
    long long n;
    int q;
    cin >> n >> q;

    for (int i = 0; i < q; i++) {
        long long ui;
        string si;
        cin >> ui >> si;

        for (char c : si) {
            if (c == 'U') {
                ui = ui / 2;
            } else if (c == 'L') {
                if (ui % 2 != 0) {
                    continue;
                }
                ui = ui * 2 + 1;
            } else if (c == 'R') {
                if (ui % 2 != 1) {
                    continue;
                }
                ui = ui * 2 + 2;
            }
        }

        cout << ui << endl;
    }

    return 0;
}