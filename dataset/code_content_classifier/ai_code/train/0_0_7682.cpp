#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> A(3*N);
    vector<int> B(3*N);

    for (int i = 0; i < 3*N; i++) {
        cin >> A[i];
    }

    for (int i = 0; i < 3*N; i++) {
        cin >> B[i];
    }

    unordered_map<int, int> countA, countB;

    for (int i = 0; i < 3*N; i++) {
        countA[A[i]]++;
        countB[B[i]]++;
    }

    for (int i = 1; i <= N; i++) {
        if (countA[i] != 3 || countB[i] != 3) {
            cout << -1 << endl;
            return 0;
        }
    }

    int operations = 0;

    for (int i = 0; i < 3*N; i++) {
        if (A[i] == B[i]) {
            continue;
        }

        for (int j = i + 1; j < 3*N; j++) {
            if (A[j] == B[i]) {
                while (j > i) {
                    swap(A[j], A[j-1]);
                    j--;
                    operations++;
                }
                break;
            }
        }
    }

    cout << operations << endl;

    return 0;
}