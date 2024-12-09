#include <iostream>
#include <vector>

int main() {
    int n, q;
    std::cin >> n >> q;

    std::vector<int> working_days(n, 1); // Initially all days are working days
    int working_days_count = n;

    for (int i = 0; i < q; i++) {
        int l, r, k;
        std::cin >> l >> r >> k;

        for (int j = l - 1; j < r; j++) {
            if (k == 1 && working_days[j] == 1) {
                working_days[j] = 0;
                working_days_count--;
            } else if (k == 2 && working_days[j] == 0) {
                working_days[j] = 1;
                working_days_count++;
            }
        }

        std::cout << working_days_count << std::endl;
    }

    return 0;
}