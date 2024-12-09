#include <iostream>
#include <cmath>

const double pi = 3.1415926535;
const double radius = 6378.1;

double deg2rad(double deg) {
    return deg * pi / 180;
}

int main() {
    double lat1, lon1, lat2, lon2;
    
    while (std::cin >> lat1 >> lon1 >> lat2 >> lon2) {
        if (lat1 == -1 && lon1 == -1 && lat2 == -1 && lon2 == -1) {
            break;
        }
        
        lat1 = deg2rad(lat1);
        lon1 = deg2rad(lon1);
        lat2 = deg2rad(lat2);
        lon2 = deg2rad(lon2);
        
        double surface_distance = radius * acos(sin(lat1) * sin(lat2) + cos(lat1) * cos(lat2) * cos(lon1 - lon2));
        
        // Round off to the nearest whole number
        int rounded_distance = std::round(surface_distance);
        
        std::cout << rounded_distance << std::endl;
    }
    
    return 0;
}