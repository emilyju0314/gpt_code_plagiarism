#include <iostream>
#include <cmath>

int main() {
    double moon_angle, time;
    std::cin >> moon_angle >> time;

    // Convert moon position to radians
    double moon_angle_rad = moon_angle * M_PI / 180.0;

    // Calculate the time when Kaguya hides behind the moon
    double orbit_radius = 380000.0; // in km
    double moon_radius = 1800.0; // in km
    double kaguya_altitude = 100.0; // in km

    double velocity_km_per_minute = orbit_radius * 2 * M_PI / (250000.0 / 60); // in km/min
    double angle_per_minute = 360.0 / (250000.0 / 60); // in degrees/min

    double kaguya_hides_time = 0.0;

    while (true) {
        double kaguya_position_x = orbit_radius + kaguya_altitude * cos(moon_angle_rad);
        double kaguya_position_z = kaguya_altitude * sin(moon_angle_rad);
        
        if (kaguya_position_z <= moon_radius) {
            break;
        }

        kaguya_hides_time += 1.0;
        moon_angle += angle_per_minute;
        moon_angle_rad = moon_angle * M_PI / 180.0;
    }

    std::cout << kaguya_hides_time << std::endl;

    return 0;
}