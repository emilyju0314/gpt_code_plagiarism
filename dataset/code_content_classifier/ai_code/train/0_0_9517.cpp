#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, K;
    cin >> N >> K;

    vector<int> A(N);
    for(int i = 0; i < N; i++) {
        cin >> A[i];
    }

    vector<int> sheets;

    for(int L = 0; L < N; L++) {
        int xor_val = 0;
        for(int R = L; R < N; R++) {
            xor_val ^= A[R];
            sheets.push_back(xor_val);
        }
    }

    sort(sheets.begin(), sheets.end(), greater<int>());

    cout << sheets[K-1] << endl;

    return 0;
}