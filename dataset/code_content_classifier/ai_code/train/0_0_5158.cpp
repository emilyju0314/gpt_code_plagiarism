#include <iostream>
#include <cmath>

int main() {
    int s, x1, x2, t1, t2, p, d;
    std::cin >> s >> x1 >> x2 >> t1 >> t2 >> p >> d;

    int travel_time = std::abs(x2 - x1) * t2;
    int tram_position = p;
    int tram_direction = d;

    if (x1 < x2) {
        if (tram_direction == 1) {
            if (x1 < tram_position && tram_position < x2) {
                int tram_travel_time = std::abs(tram_position - x1) * t1;
                int time_to_exit_tram = t1;
                travel_time = std::min(travel_time, tram_travel_time + time_to_exit_tram + t2);
            } else {
                travel_time = std::min(travel_time, std::abs(tram_position - x1) * t1);
            }
        } else {
            int tram_travel_time = (s - tram_position + s + x1) * t1;
            if (x1 < tram_position) {
                tram_travel_time = (s - tram_position + s + x1) * t1;
            }
            else {
                tram_travel_time = (s + tram_position + s - x1) * t1;
            }
            int time_to_exit_tram = t1;
            travel_time = std::min(travel_time, tram_travel_time + time_to_exit_tram + t2);
        }
    } else {
        if (tram_direction == 1) {
            int tram_travel_time = (s - tram_position + s + x1) * t1;
            if (x1 < tram_position) {
                tram_travel_time = (s - tram_position + s + x1) * t1;
            }
            else {
                tram_travel_time = (s + tram_position + s - x1) * t1;
            }
            int time_to_exit_tram = t1;
            travel_time = std::min(travel_time, tram_travel_time + time_to_exit_tram + t2);
        } else {
            if (x2 < tram_position && tram_position < x1) {
                int tram_travel_time = std::abs(tram_position - x1) * t1;
                int time_to_exit_tram = t1;
                travel_time = std::min(travel_time, tram_travel_time + time_to_exit_tram + t2);
            } else {
                travel_time = std::min(travel_time, std::abs(tram_position - x1) * t1);
            }
        }
    }

    std::cout << travel_time << std::endl;

    return 0;
}