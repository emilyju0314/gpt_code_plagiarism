#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

struct Color {
    double L, a, b;
};

double calculateDistance(Color c1, Color c2) {
    return (c1.L - c2.L) * (c1.L - c2.L) + (c1.a - c2.a) * (c1.a - c2.a) + (c1.b - c2.b) * (c1.b - c2.b);
}

int main() {
    int N, M;
    cin >> N >> M;
    
    vector<Color> colors(N);
    for(int i = 0; i < N; i++) {
        cin >> colors[i].L >> colors[i].a >> colors[i].b;
    }
    
    double maxDistance = 0;
    for(int i = 0; i < (1 << N); i++) {
        if(__builtin_popcount(i) == M) {
            vector<Color> selectedColors;
            for(int j = 0; j < N; j++) {
                if(i & (1 << j)) {
                    selectedColors.push_back(colors[j]);
                }
            }
            
            double totalDistance = 0;
            for(int j = 0; j < selectedColors.size(); j++) {
                for(int k = j + 1; k < selectedColors.size(); k++) {
                    totalDistance += calculateDistance(selectedColors[j], selectedColors[k]);
                }
            }
            
            maxDistance = max(maxDistance, totalDistance);
        }
    }
    
    cout << fixed;
    cout.precision(20);
    cout << maxDistance << endl;
    
    return 0;
}