#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for(int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    int left = 0, right = 0;
    int min_time = -1;

    for(int i = 1; i < n - 1; i++) {
        if(a[i] <= a[i-1] && a[i] <= a[i+1]) {
            min_time = 0;
            break;
        }
    }

    if(min_time == -1) {
        for(int T = 1; T < n; T++) {
            left = a[T-1];
            right = a[T+1];

            for(int i = T; i > 0; i--) {
                left = std::min(left, a[i]);
                if((T-i) >= left) {
                    min_time = (T-i) + 1;
                    break;
                }
            }

            for(int i = T; i < n; i++) {
                right = std::min(right, a[i]);
                if((i-T) >= right) {
                    min_time = (i-T) + 1;
                    break;
                }
            }

            if(min_time != -1) break;
        }
    }

    std::cout << min_time << std::endl;

    return 0;
}