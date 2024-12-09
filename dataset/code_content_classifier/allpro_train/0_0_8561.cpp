#include <iostream>
#include <vector>
#include <cmath>

struct Dog {
    double x, y, vx, vy;
    int frisbeeCount = 0;
};

struct Frisbee {
    double x, y, vx, vy;
};

bool canGetFrisbee(Dog dog, Frisbee frisbee) {
    double dist = sqrt(pow(dog.x - frisbee.x, 2) + pow(dog.y - frisbee.y, 2));
    double timeToGet = dist / sqrt(pow(dog.vx, 2) + pow(dog.vy, 2));
    double timeToLaunch = dist / sqrt(pow(frisbee.vx, 2) + pow(frisbee.vy, 2));
    
    return timeToGet <= timeToLaunch;
}

int main() {
    int N, M;
    while (std::cin >> N >> M && N != 0 && M != 0) {
        std::vector<Dog> dogs(N);
        std::vector<Frisbee> frisbees(M);

        for (int i = 0; i < N; ++i) {
            std::cin >> dogs[i].x >> dogs[i].y >> dogs[i].vx >> dogs[i].vy;
        }

        for (int i = 0; i < M; ++i) {
            std::cin >> frisbees[i].x >> frisbees[i].y >> frisbees[i].vx >> frisbees[i].vy;
        }

        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                if (canGetFrisbee(dogs[j], frisbees[i])) {
                    dogs[j].frisbeeCount++;
                    break;
                    
                }
            }
        }

        for (int i = 0; i < N; ++i) {
            std::cout << dogs[i].frisbeeCount << (i == N-1 ? "\n" : " ");
        }
    }

    return 0;
}