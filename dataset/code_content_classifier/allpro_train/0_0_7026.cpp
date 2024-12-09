#include <iostream>
#include <vector>

int main() {
    int t;
    std::cin >> t;

    while(t--) {
        int n;
        std::cin >> n;

        std::vector<int> a(n);
        int sum = 0, zeros = 0, negatives = 0;
        for(int i = 0; i < n; i++) {
            std::cin >> a[i];
            sum += a[i];
            if(a[i] == 0)
                zeros++;
            if(a[i] < 0)
                negatives++;
        }

        int steps = 0;
        if(sum == 0) {
            steps = zeros == n ? 1 : 2;
        } else if(negatives % 2 == 1 && zeros == 0) {
            steps = 2;
        }

        std::cout << steps << std::endl;
    }

    return 0;
}