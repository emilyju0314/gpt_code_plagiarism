#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        int q, d;
        cin >> q >> d;

        vector<int> lucky(10, 0);
        for(int i = d; i <= 9; i++) {
            lucky[i] = 1;
        }

        for(int i = 1; i <= 9; i++) {
            for(int j = i; j < 10; j++) {
                lucky[j] = max(lucky[j], lucky[j-i]);
            }
        }

        for(int i = 0; i < q; i++) {
            int a;
            cin >> a;

            if(a >= d * 10 || lucky[a % 10]) {
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }
        }
    }

    return 0;
}