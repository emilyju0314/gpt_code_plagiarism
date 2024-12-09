#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> gems(N);
    for (int i = 0; i < N; i++) {
        cin >> gems[i];
    }

    int ans = 0;
    for (int i = 1; i <= N; i++) {
        int sum = 0;
        for (int j = i; j <= N; j += i) {
            sum += gems[j-1];
        }
        if (sum > 0) {
            ans += sum;
        }
    }

    cout << ans << endl;

    return 0;
}