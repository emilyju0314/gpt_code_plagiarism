#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
    int m, h1, a1, x1, y1, h2, a2, x2, y2;
    cin >> m >> h1 >> a1 >> x1 >> y1 >> h2 >> a2 >> x2 >> y2;

    unordered_map<int, int> Xaniar, Abol;
    int value = h1;
    for (int i = 1; i <= m; i++) {
        Xaniar[value] = i;
        value = (x1 * value + y1) % m;
    }
    
    value = h2;
    for (int i = 1; i <= m; i++) {
        Abol[value] = i;
        value = (x2 * value + y2) % m;
    }

    int min_time = INT_MAX;
    for (int i = 0; i < m; i++) {
        if (Xaniar.find(a1) != Xaniar.end() && Abol.find(a2) != Abol.end()) {
            if (Xaniar[a1] == Abol[a2] && Xaniar[a1] > i) {
                min_time = min(min_time, Xaniar[a1] - i);
            }
        }
        a1 = (x1 * a1 + y1) % m;
        a2 = (x2 * a2 + y2) % m;
    }

    if (min_time == INT_MAX) {
        cout << -1 << endl;
    } else {
        cout << min_time << endl;
    }

    return 0;
}