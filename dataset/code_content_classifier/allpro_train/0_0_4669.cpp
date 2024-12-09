#include <iostream>
#include <vector>
#include <cmath>

struct Troop {
    int x, y, v;
};

struct Base {
    int x, y;
};

double calculateDistance(int x1, int y1, int x2, int y2) {
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

int main() {
    int N, M;
    
    while (true) {
        std::cin >> N >> M;
        
        if (N == 0 && M == 0) {
            break;
        }
        
        std::vector<Troop> troops(N);
        std::vector<Base> bases(M);
        
        for (int i = 0; i < N; i++) {
            std::cin >> troops[i].x >> troops[i].y >> troops[i].v;
        }
        
        for (int i = 0; i < M; i++) {
            std::cin >> bases[i].x >> bases[i].y;
        }
        
        double minTime = 1e9;
        
        for (int i = 0; i < M; i++) {
            double time = 0;
            
            for (int j = 0; j < N; j++) {
                double distance = calculateDistance(troops[j].x, troops[j].y, bases[i].x, bases[i].y);
                time = std::max(time, distance / troops[j].v);
            }
            
            minTime = std::min(minTime, time);
        }
        
        std::cout << minTime << std::endl;
    }
    
    return 0;
}