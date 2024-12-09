#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, K;
    cin >> N >> K;

    vector<int> a(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }

    int unnecessary = 0;
    for (int i = 0; i < N; i++) {
        int sum = 0;
        for (int j = 0; j < N; j++) {
            if (j == i) continue;

            sum += a[j];
            if (sum >= K) {
                unnecessary++;
                break;
            }
        }
    }

    cout << N - unnecessary << endl;

    return 0;
}