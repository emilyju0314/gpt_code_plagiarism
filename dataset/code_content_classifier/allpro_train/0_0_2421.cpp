#include <iostream>
#include <vector>
#include <cmath>

struct LightSource {
    int x, y, r, theta, alpha, beta, max_power;
};

double calculate_intensity(const LightSource& target, const std::vector<LightSource>& sources, double power) {
    double total_intensity = 0;
    for (const auto& source : sources) {
        double distance = sqrt(pow(target.x - source.x, 2) + pow(target.y - source.y, 2));
        if (distance <= source.r + target.r) {
            double angle_to_source = atan2(source.y - target.y, source.x - target.x) * 180 / M_PI;
            double angle_diff = fabs(angle_to_source - target.beta);
            if (angle_diff <= target.theta/2) {
                double intensity = power * (1 - distance/source.r) * (1 - angle_diff/(target.theta/2));
                total_intensity += intensity;
                if (total_intensity > source.max_power) {
                    total_intensity = source.max_power;
                }
            }
        }
    }
    return total_intensity;
}

int main() {
    int n;
    std::cin >> n;

    int power;
    std::cin >> power;

    LightSource target;
    std::cin >> target.x >> target.y >> target.r >> target.theta >> target.alpha >> target.beta;

    std::vector<LightSource> sources(n);
    for (int i = 0; i < n; i++) {
        std::cin >> sources[i].x >> sources[i].y >> sources[i].r >> 
            sources[i].theta >> sources[i].alpha >> sources[i].beta >> sources[i].max_power;
    }

    double max_intensity = calculate_intensity(target, sources, power);
    std::cout << max_intensity << std::endl;

    return 0;
}