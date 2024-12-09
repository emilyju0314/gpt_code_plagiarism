#include <iostream>
#include <cmath>

int main() {
    int A, B, C, D, E, F;
    std::cin >> A >> B >> C >> D >> E >> F;

    int max_sugar_water = 0;
    int max_sugar = 0;

    for (int water_A = 0; water_A <= F / 100; water_A += A) {
        for (int water_B = 0; water_B <= F / 100; water_B += B) {
            int water = 100 * water_A + 100 * water_B;
            if (water == 0 || water > F) {
                continue;
            }

            for (int sugar_C = 0; sugar_C <= E * water / 100; sugar_C += C) {
                for (int sugar_D = 0; sugar_D <= E * water / 100; sugar_D += D) {
                    int sugar = sugar_C + sugar_D;
                    if (sugar > E * water) {
                        continue;
                    }

                    int total_mass = water + sugar;
                    if (total_mass > F) {
                        continue;
                    }

                    double density = (double)(sugar * 100) / total_mass;
                    if (density > max_sugar_water) {
                        max_sugar_water = density;
                        max_sugar = sugar;
                    }
                }
            }
        }
    }

    std::cout << max_sugar_water << " " << max_sugar << std::endl;

    return 0;
}