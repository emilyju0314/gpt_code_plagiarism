#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, q;
    cin >> n >> q;

    vector<int> A(n, 0);

    for (int i = 0; i < q; i++) {
        int com, x, y;
        cin >> com >> x >> y;

        if (com == 0) {
            A[x-1] += y;
        } else if (com == 1) {
            int sum = 0;
            for (int j = x-1; j <= y-1; j++) {
                sum += A[j];
            }
            cout << sum << endl;
        }
    }

    return 0;
}