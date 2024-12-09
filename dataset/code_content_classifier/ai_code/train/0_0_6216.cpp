#include <iostream>
#include <vector>

int main() {
    int N, Q;
    std::cin >> N >> Q;

    std::vector<long long> q(Q);
    for (int i = 0; i < Q; i++) {
        std::cin >> q[i];
    }

    std::vector<long long> ans(N+1, 0);

    for (int i = 0; i < Q; i++) {
        int cnt = 0;
        long long sum = 0;
        for (int j = 1; j <= N; j++) {
            sum += ans[j];
            if (sum < q[i]) {
                ans[j] = 0;
            } else {
                ans[j] = sum / q[i];
                cnt++;
            }
        }
        ans[cnt+1] += 1;
    }

    for (int i = 1; i <= N; i++) {
        std::cout << ans[i] << "\n";
    }

    return 0;
}