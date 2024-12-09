#include <iostream>
#include <cmath>

using namespace std;

int main() {
    double D;
    while (cin >> D && D != 0) {
        double px, py, vx, vy;
        cin >> px >> py >> vx >> vy;

        double distance = 0;
        double x = px, y = py;

        while (distance <= D) {
            double next_x = x + vx;
            double next_y = y + vy;
            if (sqrt(next_x * next_x + next_y * next_y) <= 1.0) {
                double dot_product = vx * (-x) + vy * (-y);
                double length_squared = vx * vx + vy * vy;
                double reflection_x = (2 * dot_product * (-x) / length_squared) + vx;
                double reflection_y = (2 * dot_product * (-y) / length_squared) + vy;
                vx = reflection_x;
                vy = reflection_y;
            }
            x += vx;
            y += vy;
            distance += sqrt(vx * vx + vy * vy);
        }

        if (distance - D <= 1e-6) {
            cout << fixed << distance << endl;
        } else {
            cout << "impossible" << endl;
        }
    }
    
    return 0;
}