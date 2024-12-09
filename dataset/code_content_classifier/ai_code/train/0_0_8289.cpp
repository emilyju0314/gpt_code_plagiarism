#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    int count = 0;
    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= n; j++) {
            for(int k = 0; k <= n; k++) {
                for(int l = 0; l <= n; l++) {
                    if(i + 5*j + 10*k + 50*l == n) {
                        count++;
                    }
                }
            }
        }
    }

    cout << count << endl;

    return 0;
}