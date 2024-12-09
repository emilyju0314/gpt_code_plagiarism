#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, Q;
    cin >> N >> Q;

    vector<long long> a(N);
    for(int i = 0; i < N; i++) {
        cin >> a[i];
    }

    vector<long long> x(Q);
    for(int i = 0; i < Q; i++) {
        cin >> x[i];
    }

    vector<long long> prefix_sum(N);
    prefix_sum[0] = a[0];
    for(int i = 1; i < N; i++) {
        prefix_sum[i] = prefix_sum[i-1] + a[i];
    }

    for(int i = 0; i < Q; i++) {
        long long count = 0;
        for(int l = 0; l < N; l++) {
            for(int r = l; r < N; r++) {
                long long sum = prefix_sum[r] - (l > 0 ? prefix_sum[l-1] : 0);
                if(sum <= x[i]) {
                    count++;
                }
            }
        }
        cout << count << endl;
    }

    return 0;
}