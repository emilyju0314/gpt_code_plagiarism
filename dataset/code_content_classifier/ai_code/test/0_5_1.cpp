#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

bool checkRadius(double radius, int k, const vector<pair<double, double>>& habitat) {
    int count = 0;
    
    for (const auto& h : habitat) {
        double distance = sqrt(h.first * h.first + h.second * h.second);
        if (distance <= radius) {
            count++;
        }
    }
    
    return count >= k;
}

double binarySearch(int k, const vector<pair<double, double>>& habitat) {
    double low = 0.0;
    double high = 200000.0;
    
    while (high - low > 1e-6) {
        double mid = low + (high - low) / 2.0;
        
        if (checkRadius(mid, k, habitat)) {
            high = mid;
        } else {
            low = mid;
        }
    }
    
    return low;
}

int main() {
    int n, k;
    cin >> n >> k;
    
    vector<pair<double, double>> habitat(n);
    
    for (int i = 0; i < n; i++) {
        double x, y;
        cin >> x >> y;
        habitat[i] = {x, y};
    }
    
    double minRadius = binarySearch(k, habitat);
    cout << fixed;
    cout.precision(10);
    cout << minRadius << endl;
    
    return 0;
}