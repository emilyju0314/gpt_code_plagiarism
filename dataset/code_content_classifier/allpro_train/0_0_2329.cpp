#include <iostream>
#include <vector>
#include <algorithm>

struct Fish {
    int x1, y1, d1, x2, y2, d2;
};

int main() {
    int N, K;
    std::cin >> N >> K;

    std::vector<Fish> fish(N);
    for(int i = 0; i < N; i++) {
        std::cin >> fish[i].x1 >> fish[i].y1 >> fish[i].d1 >> fish[i].x2 >> fish[i].y2 >> fish[i].d2;
    }

    long long volume = 0;
    for(int x = 0; x < 1000000; x++) {
        for(int y = 0; y < 1000000; y++) {
            for(int d = 0; d < 1000000; d++) {
                int count = 0;
                for(const Fish& f : fish) {
                    if(x >= f.x1 && x < f.x2 && y >= f.y1 && y < f.y2 && d >= f.d1 && d < f.d2) {
                        count++;
                    }
                }
                if(count >= K) {
                    volume++;
                }
            }
        }
    }

    std::cout << volume << std::endl;

    return 0;
}