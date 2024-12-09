#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }

    int s, f;
    std::cin >> s >> f;

    int max_participants = 0;
    int start_hour = 0;

    for (int i = 0; i < n; ++i) {
        int num_participants = 0;
        for (int j = 0; j < n; ++j) {
            int curr_hour = (s + j) % n + 1;
            if (curr_hour <= f) {
                int idx = (i + j) % n;
                num_participants += a[idx];
            }
        }

        if (num_participants > max_participants) {
            max_participants = num_participants;
            start_hour = (i + 1) % n + 1;
        }
    }

    std::cout << start_hour << std::endl;

    return 0;
}