#include <iostream>
#include <vector>

using namespace std;

struct Satellite {
    int x, y;
};

bool checkCommunication(const Satellite& sat1, const Satellite& sat2, int r) {
    // Calculate the distance between the two satellites
    double distance = sqrt(pow(sat1.x - sat2.x, 2) + pow(sat1.y - sat2.y, 2));
    
    // Check if the distance is within the radius of the planet
    if (distance <= 2*r) {
        return true;
    } else {
        return false;
    }
}

int main() {
    int r, n;
    cin >> r >> n;
    
    vector<Satellite> satellites;
    
    for (int i = 0; i < n; i++) {
        int event;
        cin >> event;
        
        if (event == 1) {
            int x, y;
            cin >> x >> y;
            satellites.push_back({x, y});
        } else if (event == 2) {
            int index;
            cin >> index;
            satellites.erase(satellites.begin() + index - 1);
        } else if (event == 3) {
            int i, j;
            cin >> i >> j;
            
            // Check if communication is possible between satellites i and j
            if (checkCommunication(satellites[i-1], satellites[j-1], r)) {
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }
        }
    }
    
    return 0;
}