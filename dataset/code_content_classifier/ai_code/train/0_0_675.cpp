#include <iostream>
#include <vector>
#include <cmath>

struct Flower {
    int x, y, angle;
    double range;
};

struct WindRecord {
    int direction, strength;
};

struct House {
    int x, y;
    int days = 0;
};

int main() {
    int H, R;
    while (std::cin >> H >> R && H != 0 && R != 0) {
        std::vector<House> houses(H);
        for (int i = 0; i < H; ++i) {
            std::cin >> houses[i].x >> houses[i].y;
        }

        int U, M, S, du, dm, ds;
        std::cin >> U >> M >> S >> du >> dm >> ds;
        Flower plum {0, 0, du, 0};
        Flower peach {0, 0, dm, 0};
        Flower cherry {0, 0, ds, 0};

        for (int i = 0; i < U; ++i) {
            std::cin >> plum.x >> plum.y;
        }
        for (int i = 0; i < M; ++i) {
            std::cin >> peach.x >> peach.y;
        }
        for (int i = 0; i < S; ++i) {
            std::cin >> cherry.x >> cherry.y;
        }

        std::vector<WindRecord> wind_records(R);
        for (int i = 0; i < R; ++i) {
            std::cin >> wind_records[i].direction >> wind_records[i].strength;
        }

        std::vector<int> candidate_houses;
        int max_days = 0;
        for (int i = 0; i < H; ++i) {
            int days = 0;
            for (const auto& wind_record : wind_records) {
                double wind_x = wind_record.strength * std::cos(wind_record.direction);
                double wind_y = wind_record.strength * std::sin(wind_record.direction);

                int x = houses[i].x, y = houses[i].y;

                double distance_to_plum = std::sqrt(std::pow(plum.x - x, 2) + std::pow(plum.y - y, 2));
                if (distance_to_plum <= plum.range) {
                    double angle_to_plum = std::atan2(plum.y - y, plum.x - x);
                    double angle_diff = std::abs(angle_to_plum - wind_record.direction);
                    if (angle_diff <= plum.angle) {
                        days++;
                    }
                }
            }

            if (days > max_days) {
                max_days = days;
                candidate_houses.clear();
                candidate_houses.push_back(i + 1);
            } else if (days == max_days) {
                candidate_houses.push_back(i + 1);
            }
        }

        if (max_days == 0) {
            std::cout << "NA\n";
        } else {
            for (int i = 0; i < candidate_houses.size(); ++i) {
                std::cout << candidate_houses[i];
                if (i < candidate_houses.size() - 1) {
                    std::cout << " ";
                }
            }
            std::cout << "\n";
        }
    }

    return 0;
}