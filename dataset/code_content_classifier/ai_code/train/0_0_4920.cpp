#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int Q;
    cin >> Q;

    for (int i = 0; i < Q; i++) {
        int c, a, n;
        cin >> c >> a >> n;

        int teams = 0;
        while (c >= 1 && a >= 1 && n >= 1) {
            teams++;
            c--;
            a--;
            n--;
        }

        cout << teams << endl;
    }

    return 0;
}