#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, Q;
    cin >> N >> Q;

    vector<long long> cnt(N, 0);
    vector<long long> sum(N, 0);

    for (int i = 0; i < Q; i++) {
        int a;
        long long b;
        cin >> a >> b;
        cnt[a-1]++;
        sum[a-1] += b;
    }

    long long eaten = 0;
    vector<long long> dishes(N, 0);

    for (int i = 0; i < N; i++) {
        eaten += sum[i] - cnt[i];
        dishes[i] = sum[i] - eaten;
    }

    for (int i = 0; i < N; i++) {
        cout << dishes[i] << endl;
    }

    return 0;
}