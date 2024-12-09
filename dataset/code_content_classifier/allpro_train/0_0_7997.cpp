#include <iostream>
#include <vector>
#include <iomanip>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> sequence(1, 0);
    double sum = 0.0;
    
    for (int i = 0; i < n; i++) {
        int type;
        std::cin >> type;

        if (type == 1) {
            int a, x;
            std::cin >> a >> x;
            for (int j = 0; j < a; j++) {
                sum += x;
                sequence[j] += x;
            }
        } else if (type == 2) {
            int k;
            std::cin >> k;
            sum += k;
            sequence.push_back(k);
        } else {
            sum -= sequence.back();
            sequence.pop_back();
        }

        int size = sequence.size();
        std::cout << std::setprecision(6) << std::fixed << (sum / size) << std::endl;
    }

    return 0;
}