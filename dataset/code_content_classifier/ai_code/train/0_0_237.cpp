#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int fares[7][7] = {
        {0, 300, 500, 600, 700, 1350, 1650},
        {300, 0, 350, 450, 600, 1150, 1500},
        {500, 350, 0, 250, 400, 1000, 1350},
        {600, 450, 250, 0, 250, 850, 1300},
        {700, 600, 400, 250, 0, 600, 1150},
        {1350, 1150, 1000, 850, 600, 0, 500},
        {1650, 1500, 1350, 1300, 1150, 500, 0}
    };

    int d, hd, md, a, ha, ma;

    while(true) {
        cin >> d;
        if(d == 0) break;

        cin >> hd >> md >> a >> ha >> ma;

        int distance = abs(d - a); // Calculate the distance between departure and arrival IC
        int fare = fares[d-1][a-1]; // Get the fare for the distance

        // Check if the transit time is between 17:30 and 19:30 and distance is less than 40km
        if((hd > 17 || (hd == 17 && md >= 30)) && (ha < 19 || (ha == 19 && ma <= 30)) && distance <= 40) {
            fare = ceil(fare/2.0) * 50; // Calculate discounted fare and round up
        }

        cout << fare << endl;
    }

    return 0;
}