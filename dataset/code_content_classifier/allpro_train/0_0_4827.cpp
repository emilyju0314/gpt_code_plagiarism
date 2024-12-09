#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<int> a(2*N);
    for (int i = 0; i < 2*N; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    int minZ = 0;
    for (int i = 0; i < N; i++) {
        minZ = max(minZ, (a[i] + a[2*N-1-i]) % M);
    }

    cout << minZ << endl;

    return 0;
}