#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int N, M, K;
    std::cin >> N >> M >> K;
    
    std::vector<int> a(N), b(N);
    for(int i = 0; i < N; i++) {
        std::cin >> a[i];
    }
    for(int i = 0; i < N; i++) {
        std::cin >> b[i];
    }

    int maxPotatoes = 0;
    for(int i = 1; i <= M; i++) {
        int totalPotatoes = i;
        std::vector<int> fields(N, 0);
        
        do {
            fields[0] += totalPotatoes;
            for(int j = 0; j < N; j++) {
                if (fields[j] >= a[j]) {
                    fields[j + 1] += fields[j] / a[j] * b[j];
                    fields[j] %= a[j];
                }
            }
            totalPotatoes = fields[N-1];
        } while (totalPotatoes > 0 && totalPotatoes != i);

        if (fields[N-1] > maxPotatoes) {
            maxPotatoes = fields[N-1];
        }
    }

    std::cout << maxPotatoes << std::endl;

    return 0;
}