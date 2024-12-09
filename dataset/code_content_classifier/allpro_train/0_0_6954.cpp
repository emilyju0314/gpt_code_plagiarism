#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

struct Driver {
    string name;
    int points;
    int wins;
    int secondPlaces;
    int thirdPlaces;
    // Add more variables for additional places if needed
    
    Driver(string n) : name(n), points(0), wins(0), secondPlaces(0), thirdPlaces(0) {}
};

bool cmp(const Driver &a, const Driver &b) {
    if(a.points != b.points) return (a.points > b.points);
    if(a.wins != b.wins) return (a.wins > b.wins);
    // Compare additional places here if needed
    return (a.name < b.name);
}

int main() {
    int t;
    cin >> t;
    
    unordered_map<string, Driver> drivers;
    
    for(int i = 0; i < t; i++) {
        int n;
        cin >> n;
        
        for(int j = 0; j < n; j++) {
            string name;
            cin >> name;
            if(drivers.find(name) == drivers.end()) {
                drivers[name] = Driver(name);
            }
            drivers[name].points += (j < 10) ? (25 - 7*j) : 0;
            drivers[name].wins += (j == 0) ? 1 : 0;
            drivers[name].secondPlaces += (j == 1) ? 1 : 0;
            drivers[name].thirdPlaces += (j == 2) ? 1 : 0;
        }
    }
    
    vector<Driver> sortedDrivers;
    for(auto it = drivers.begin(); it != drivers.end(); it++) {
        sortedDrivers.push_back(it->second);
    }
    
    sort(sortedDrivers.begin(), sortedDrivers.end(), cmp);
    
    cout << sortedDrivers[0].name << endl;
    
    // Recalculate drivers for alternative scoring
    for(auto& d : sortedDrivers) {
        d = Driver(d.name);
    }
    
    for(int i = 0; i < t; i++) {
        int n;
        cin >> n;
        
        for(int j = 0; j < n; j++) {
            string name;
            cin >> name;
            drivers[name].wins += (j == 0) ? 1 : 0;
            drivers[name].points += (j < 10) ? (25 - 7*j) : 0;
            drivers[name].secondPlaces += (j == 1) ? 1 : 0;
            drivers[name].thirdPlaces += (j == 2) ? 1 : 0;
        }
    }
    
    sort(sortedDrivers.begin(), sortedDrivers.end(), cmp);
    
    cout << sortedDrivers[0].name << endl;
    
    return 0;
}