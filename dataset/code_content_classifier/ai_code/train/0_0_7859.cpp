#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;

    if (N % 2 == 0) {
        cout << "Yes" << endl;
        cout << N << endl;
        for (int i = 1; i <= N; i++) {
            cout << 2 << " ";
            cout << i << " ";
            cout << (i % N) + 1 << endl;
        }
    } else {
        cout << "No" << endl;
    }

    return 0;
}