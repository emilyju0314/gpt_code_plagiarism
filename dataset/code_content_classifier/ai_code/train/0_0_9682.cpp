#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> b(N);
    for (int i = 0; i < N; i++) {
        cin >> b[i];
    }

    vector<int> a;
    for (int i = 0; i < N; i++) {
        bool inserted = false;
        for (int j = i; j >= 0; j--) {
            if (b[j] == j + 1) {
                a.insert(a.begin() + j, j + 1);
                inserted = true;
                break;
            }
        }
        if (!inserted) {
            cout << -1;
            return 0;
        }
    }

    for (int num : a) {
        cout << num << endl;
    }

    return 0;
}