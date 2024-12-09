#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> bills(n);
    for(int i = 0; i < n; i++) {
        cin >> bills[i];
    }

    int change25 = 0, change50 = 0;

    for(int i = 0; i < n; i++) {
        if(bills[i] == 25) {
            change25++;
        } else if(bills[i] == 50) {
            change25--;
            change50++;
        } else {
            if(change50 > 0) {
                change50--;
                change25--;
            } else {
                change25 -= 3;
            }
        }

        if(change25 < 0 || change50 < 0) {
            cout << "NO" << endl;
            return 0;
        }
    }

    cout << "YES" << endl;

    return 0;
}