#include <iostream>

using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        int x, y, a, b;
        cin >> x >> y >> a >> b;

        if(a*2 <= b) {
            cout << (x + y) * a << endl;
        } else {
            int min_num = min(x, y);
            int max_num = max(x, y);
            int cost = min_num * b + (max_num - min_num) * a;
            cout << cost << endl;
        }
    }

    return 0;
}