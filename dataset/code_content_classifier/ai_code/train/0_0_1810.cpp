#include <iostream>
#include <vector>

struct Balloon {
    int x, y, z, r;
};

struct LightSource {
    int x, y, z, b;
};

double getDistance(int x1, int y1, int z1, int x2, int y2, int z2) {
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2) + (z1 - z2) * (z1 - z2));
}

double getTotalIllumination(const std::vector<Balloon>& balloons, const std::vector<LightSource>& lights, int r, int ex, int ey, int ez) {
    double totalIntensity = 0.0;
    
    for (const auto& light : lights) {
        bool obstructed = false;
        for (const auto& balloon : balloons) {
            double distance = getDistance(light.x, light.y, light.z, balloon.x, balloon.y, balloon.z);
            if (distance < balloon.r) {
                obstructed = true;
                break;
            }
        }
        
        if (!obstructed) {
            double distanceToObjective = getDistance(light.x, light.y, light.z, ex, ey, ez);
            totalIntensity += static_cast<double>(light.b) / (distanceToObjective * distanceToObjective);
        }
    }
    
    return totalIntensity;
}

int main() {
    int N, M, R;
    
    while (true) {
        std::cin >> N >> M >> R;
        
        if (N == 0 && M == 0 && R == 0) {
            break;
        }
        
        std::vector<Balloon> balloons(N);
        std::vector<LightSource> lights(M);
        int ex, ey, ez;
        
        for (int i = 0; i < N; i++) {
            std::cin >> balloons[i].x >> balloons[i].y >> balloons[i].z >> balloons[i].r;
        }
        
        for (int i = 0; i < M; i++) {
            std::cin >> lights[i].x >> lights[i].y >> lights[i].z >> lights[i].b;
        }
        
        std::cin >> ex >> ey >> ez;
        
        double maxIntensity = 0.0;
        
        for (int mask = 0; mask < (1 << N); mask++) {
            if (__builtin_popcount(mask) <= R) {
                std::vector<Balloon> removedBalloons;
                for (int i = 0; i < N; i++) {
                    if ((mask >> i) & 1) {
                        removedBalloons.push_back(balloons[i]);
                    }
                }
                
                double intensity = getTotalIllumination(removedBalloons, lights, R, ex, ey, ez);
                maxIntensity = std::max(maxIntensity, intensity);
            }
        }
        
        std::cout.precision(10);
        std::cout << maxIntensity << std::endl;
    }
    
    return 0;
}