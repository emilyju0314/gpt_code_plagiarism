#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, A, B;
    cin >> N >> A >> B;

    if (A + B - 1 > N) {
        cout << -1 << endl;
    } else {
        vector<int> permutation(N, 0);
        int cur = 1;

        for (int i = 0; i < A; i++) {
            permutation[cur-1] = cur + B;
            cur++;
        }

        for (int i = 0; i < B; i++) {
            permutation[cur-1] = cur - A;
            cur++;
        }

        for (int i = 0; i < N; i++) {
            if (permutation[i] == 0) {
                permutation[i] = cur;
                cur++;
            }
        }

        for (int i = 0; i < N; i++) {
            cout << permutation[i] << " ";
        }
        cout << endl;
    }

    return 0;
}