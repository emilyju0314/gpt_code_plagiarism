#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        vector<int> b(7);
        for(int i = 0; i < 7; i++) {
            cin >> b[i];
        }

        int a1, a2, a3;

        a1 = b[0];
        a2 = b[1];
        a3 = b[6] - a1 - a2;

        cout << a1 << " " << a2 << " " << a3 << endl;
    }

    return 0;
}