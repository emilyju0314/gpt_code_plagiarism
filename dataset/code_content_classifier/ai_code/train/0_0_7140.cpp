#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> periods(n);
    for (int i = 0; i < n; i++) {
        cin >> periods[i];
    }

    int q;
    cin >> q;

    vector<int> cities(n + 1, 0);

    for (int i = 0; i < q; i++) {
        char c;
        int x, y;
        cin >> c >> x >> y;
        
        if (c == 'A') {
            int t = 0;
            while (x < y) {
                if (t % periods[x - 1] == 0) {
                    t++;
                } else {
                    t++;
                    x++;
                }
            }
            cout << t << endl;
        } else {
            periods[x - 1] = y;
        }
    }

    return 0;
}