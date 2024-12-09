#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, K;
    cin >> N >> K;

    vector<int> A(N), B(N);
    for(int i=0; i<N; i++) {
        cin >> A[i] >> B[i];
    }

    long long sum = 0;
    long long ans = 0;

    for(int i=0; i<N; i++) {
        sum += A[i];
        if(B[i] == 2) {
            ans += A[i];
            A[i] = 0;
        }
    }

    long long cycle = 0;
    for(int i=0; i<N; i++) {
        cycle += A[i];
    }

    if(cycle == 0) {
        cout << -1 << endl;
        return 0;
    }

    long long t = (sum + cycle - 1) / cycle;
    ans += t * cycle * 2;

    cout << ans << endl;

    return 0;
}