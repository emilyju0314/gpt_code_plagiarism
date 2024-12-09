#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, T, H, L;
    cin >> N >> T >> H >> L;

    vector<int> t(N), h(N);
    for (int i = 0; i < N; i++) {
        cin >> t[i] >> h[i];
    }

    int i = 0;
    while (true) {
        if (t[i] == 0 && h[i] == 0) {
            cout << i+1 << endl;
            break;
        }

        if (t[i] > 0) {
            T++;
            t[i]--;
        } else {
            H++;
            h[i]--;
        }

        int balance = 0;
        while (balance < 90) {
            if (T >= 1 && H >= 1) {
                balance += 90;
                T--;
                H--;
            } else if (T >= 10) {
                balance += 90;
                T -= 10;
            } else {
                break;
            }
        }

        i = (i + 1) % N;
    }

    return 0;
}