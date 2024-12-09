#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int N, Q;
    std::cin >> N >> Q;

    std::vector<int> a(N);
    for (int i = 0; i < N; i++) {
        std::cin >> a[i];
    }

    for (int i = 0; i < Q; i++) {
        int l, r;
        std::cin >> l >> r;
        
        int count = std::count_if(a.begin(), a.end(), [l, r](int x) { return x >= l && x <= r; });

        std::cout << count << std::endl;
    }

    return 0;
}