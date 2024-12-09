#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

int main() {
    int n;
    string homeAirport;
    unordered_set<string> flights;

    cin >> n >> homeAirport;

    for (int i = 0; i < n; i++) {
        string flight;
        cin >> flight;
        flights.insert(flight.substr(0, 3));
        flights.insert(flight.substr(4, 3));
    }

    if (flights.find(homeAirport) != flights.end()) {
        cout << "home" << endl;
    } else {
        cout << "contest" << endl;
    }

    return 0;
}