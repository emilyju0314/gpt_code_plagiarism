#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, K;
    cin >> N >> K;

    vector<int> a(N);
    for(int i = 0; i < N; i++) {
        cin >> a[i];
    }

    vector<int> bitwise_AND;
    for(int i = 0; i < N; i++) {
        int beauty = 0;
        for(int j = i; j < N; j++) {
            beauty += a[j];
            bitwise_AND.push_back(beauty);
        }
    }

    sort(bitwise_AND.begin(), bitwise_AND.end(), greater<int>());

    int ans = 0;
    for(int i = 0; i < K; i++) {
        ans += bitwise_AND[i];
    }

    cout << ans << endl;

    return 0;
}