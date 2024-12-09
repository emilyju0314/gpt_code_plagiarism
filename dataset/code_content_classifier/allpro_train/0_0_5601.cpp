#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;

    if (N <= 2) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
        vector<int> p(N);
        for (int i = 0; i < N; i++) {
            p[i] = N - i;
        }
        for (int i = 0; i < N; i++) {
            cout << p[i] << " ";
        }
        cout << endl;

        cout << "YES" << endl;
        vector<int> q(N);
        q[0] = N;
        q[1] = N - 1;
        q[2] = N - 2;
        for (int i = 3; i < N; i++) {
            q[i] = i - 2;
        }
        for (int i = 0; i < N; i++) {
            cout << q[i] << " ";
        }
        cout << endl;
    }

    return 0;
}