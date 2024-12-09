#include <iostream>

using namespace std;

int main() {
    int N;
    cin >> N;

    long long ans = 0;
    for (int i = 1; i <= N; i++) {
        int A;
        cin >> A;
        ans += A / 2;
    }

    cout << ans << endl;

    return 0;
}