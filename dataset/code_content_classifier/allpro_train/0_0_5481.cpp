#include <iostream>
#include <string>

int main() {
    int n;
    std::string sequenceA, sequenceB;
    std::cin >> n >> sequenceA >> sequenceB;

    int red_spots_Nikephoros = 0, red_spots_Polycarpus = 0;

    for(int i = 0; i < n; i++) {
        char a = sequenceA[i % sequenceA.size()];
        char b = sequenceB[i % sequenceB.size()];

        if(a == 'R' && b == 'S') {
            red_spots_Polycarpus++;
        } else if(a == 'S' && b == 'P') {
            red_spots_Polycarpus++;
        } else if(a == 'P' && b == 'R') {
            red_spots_Polycarpus++;
        } else if(a == 'S' && b == 'R') {
            red_spots_Nikephoros++;
        } else if(a == 'P' && b == 'S') {
            red_spots_Nikephoros++;
        } else if(a == 'R' && b == 'P') {
            red_spots_Nikephoros++;
        }
    }

    std::cout << red_spots_Nikephoros << " " << red_spots_Polycarpus << std::endl;

    return 0;
}