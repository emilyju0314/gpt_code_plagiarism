#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> tau(N);

    for (int i = 1; i <= N; i++) {
        tau[i - 1] = i;
    }

    // Ask the response program for the permutation
    cout << "?";
    for (int i = 0; i < N; i++) {
        cout << " " << tau[i];
    }
    cout << endl;

    vector<int> b(N);
    for (int i = 0; i < N; i++) {
        cin >> b[i];
    }

    // Sort the sequences in ascending order
    sort(tau.begin(), tau.end(), [&](int i, int j) {
        return b[i - 1] < b[j - 1];
    });

    // Output the identified permutation
    cout << "!";
    for (int i = 0; i < N; i++) {
        cout << " " << tau[i];
    }
    cout << endl;

    return 0;
}