#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n, x, y, z;
        cin >> n >> x >> y >> z;

        vector<long long> a(n);
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }

        // The key observation here is that the number of possible first attacks that allow the White King
        // to launch the last attack is equal to the number of castles with at least two soldiers.
        int count = 0;
        for(int i = 0; i < n; i++) {
            if(a[i] >= 2) {
                count++;
            }
        }

        // If there are only 0 or 1 castles with at least two soldiers, then the Black King can always launch the last attack
        // no matter what the White King does.
        if(count <= 1) {
            cout << "0" << endl;
        } else {
            // Otherwise, we can choose any of the castles with at least two soldiers for the first attack.
            cout << count - 1 << endl;
        }
    }

    return 0;
}