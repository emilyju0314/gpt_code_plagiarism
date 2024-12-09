#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int countOverlappingStickers(const vector<pair<double, double>>& stickers) {
    int maxOverlappingStickers = 0;
    
    for (int i = 0; i < stickers.size(); i++) {
        for (int j = i + 1; j < stickers.size(); j++) {
            double distance = sqrt(pow(stickers[i].first - stickers[j].first, 2) + 
                                   pow(stickers[i].second - stickers[j].second, 2));
            if (distance <= 2.0) {
                int overlapping = 2;
                for (int k = 0; k < stickers.size(); k++) {
                    if (k != i && k != j) {
                        double distanceToI = sqrt(pow(stickers[i].first - stickers[k].first, 2) + 
                                                  pow(stickers[i].second - stickers[k].second, 2));
                        double distanceToJ = sqrt(pow(stickers[j].first - stickers[k].first, 2) + 
                                                  pow(stickers[j].second - stickers[k].second, 2));
                        if (distanceToI <= 1.0 && distanceToJ <= 1.0) {
                            overlapping++;
                        }
                    }
                }
                maxOverlappingStickers = max(maxOverlappingStickers, overlapping);
            }
        }
    }
    
    return maxOverlappingStickers;
}

int main() {
    int n;
    while (cin >> n && n != 0) {
        vector<pair<double, double>> stickers(n);
        for (int i = 0; i < n; i++) {
            double x, y;
            char comma;
            cin >> x >> comma >> y;
            stickers[i] = make_pair(x, y);
        }
        
        cout << countOverlappingStickers(stickers) << endl;
    }
    
    return 0;
}