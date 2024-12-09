#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    if (n % 2 == 1) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
        
        for (int i = 1; i <= n; i++) {
            for (int j = i+1; j <= n; j++) {
                if ((i+j) % 2 == 0) {
                    cout << i << " " << j << endl;
                }
            }
        }
    }

    return 0;
}