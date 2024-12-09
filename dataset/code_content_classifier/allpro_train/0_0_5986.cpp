#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;

    for(int i=0; i<t; i++) {
        int a, b, c, n;
        cin >> a >> b >> c >> n;

        int total_coins = a + b + c + n;
        if(total_coins % 3 == 0 && total_coins / 3 >= max(a, max(b, c))) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}