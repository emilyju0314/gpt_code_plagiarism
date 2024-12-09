#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> U(N), D(N), L(N), R(N);
    for (int i = 0; i < N; i++) {
        cin >> U[i];
    }
    for (int i = 0; i < N; i++) {
        cin >> D[i];
    }
    for (int i = 0; i < N; i++) {
        cin >> L[i];
    }
    for (int i = 0; i < N; i++) {
        cin >> R[i];
    }

    vector<string> order;

    for (int i = 0; i < N; i++) {
        while (L[i] > 0) {
            order.push_back("L" + to_string(i+1));
            L[i]--;
        }
        while (R[i] > 0) {
            order.push_back("R" + to_string(i+1));
            R[i]--;
        }
    }

    for (int i = 0; i < N; i++) {
        while (U[i] > 0) {
            order.push_back("U" + to_string(i+1));
            U[i]--;
        }
        while (D[i] > 0) {
            order.push_back("D" + to_string(i+1));
            D[i]--;
        }
    }

    if (order.size() == N * N) {
        for (string s : order) {
            cout << s << endl;
        }
    } else {
        cout << "NO" << endl;
    }

    return 0;
}