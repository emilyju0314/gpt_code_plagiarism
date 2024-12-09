#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        int a, b, c;
        cin >> a >> b >> c;

        int total = a + b + c;
        int max_songs = max({a, b, c});
        
        if (total % 2 == 0 && max_songs <= (total / 2)) {
            cout << "0" << endl;
        } else {
            cout << max(0, total/2 + 1 - max_songs) << endl;
        }
    }

    return 0;
}