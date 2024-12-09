#include <iostream>
#include <vector>
#include <algorithm>

struct Crop {
    std::string name;
    double efficiency;

    bool operator <(const Crop& c) const {
        if (efficiency == c.efficiency) {
            return name < c.name;
        }
        return efficiency > c.efficiency;
    }
};

int main() {
    int N;
    while (true) {
        std::cin >> N;
        if (N == 0) break;

        std::vector<Crop> crops(N);
        for (int i = 0; i < N; i++) {
            Crop newCrop;
            std::cin >> newCrop.name;
            int P, A, B, C, D, E, F, S, M;
            std::cin >> P >> A >> B >> C >> D >> E >> F >> S >> M;

            double time = A + 2 + C + 10 + E;
            double income = F * S * M - P;
            newCrop.efficiency = income / time;

            crops[i] = newCrop;
        }

        std::sort(crops.begin(), crops.end());

        for (const auto& crop : crops) {
            std::cout << crop.name << std::endl;
        }

        std::cout << "#" << std::endl;
    }

    return 0;
}