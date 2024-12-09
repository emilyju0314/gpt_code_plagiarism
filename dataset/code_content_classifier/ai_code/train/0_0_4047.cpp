#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    vector<int> diffs;
    for (int i = 0; i < N - 1; i++) {
        diffs.push_back(A[i + 1] - A[i]);
    }

    int operations = 1;
    int count = 1;
    for (int i = 1; i < diffs.size(); i++) {
        if (diffs[i] == diffs[i - 1]) {
            count++;
        } else {
            operations = max(operations, count);
            count = 1;
        }
    }
    operations = max(operations, count);

    cout << N - operations << endl;

    return 0;
}