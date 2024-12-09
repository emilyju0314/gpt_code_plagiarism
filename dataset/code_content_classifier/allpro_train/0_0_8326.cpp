#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int b, g, n;
    cin >> b >> g >> n;

    int min_decks = 0;
    for (int i = 0; i <= n; i++) {
        if (i <= b && n - i <= g) {
            min_decks++;
        }
    }

    cout << min_decks << endl;

    return 0;
}