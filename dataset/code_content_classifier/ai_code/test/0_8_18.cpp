#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n, d;
        cin >> n >> d;
        vector<int> a(n);

        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }

        int steps = 0;
        vector<int> temp(n);
        
        while(true) {
            bool allZero = true;
            for(int i = 0; i < n; i++) {
                temp[i] = a[(i + n - d) % n] & a[i];
                if(temp[i] != 0) {
                    allZero = false;
                }
            }

            steps++;

            if(allZero) {
                cout << steps << endl;
                break;
            }

            a = temp;
            
            if(steps > n) {
                cout << "-1" << endl;
                break;
            }
        }
    }

    return 0;
}