#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> p(N);
    for (int i = 0; i < N; i++) {
        cin >> p[i];
    }

    vector<int> operations;
    for (int k = N-1; k >= 1; k--) {
        for (int i = k; i < N; i++) {
            if (p[i] == k) {
                operations.push_back(k);
                for (int j = i; j >= 0; j -= k) {
                    swap(p[j], p[j-k]);
                }
            }
        }
    }

    cout << operations.size() << endl;
    for (int op : operations) {
        cout << op << endl;
    }

    return 0;
}