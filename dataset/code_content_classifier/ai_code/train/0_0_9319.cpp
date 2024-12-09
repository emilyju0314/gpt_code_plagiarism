#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<string> templatePhoto(n);
    vector<vector<pair<pair<int, int>, pair<int, int>>> specialPhotos(k);

    for (int i = 0; i < n; i++) {
        cin >> templatePhoto[i];
    }

    for (int i = 0; i < k; i++) {
        int ai, bi, ci, di;
        char ei;
        cin >> ai >> bi >> ci >> di >> ei;
        specialPhotos[i].push_back(make_pair(make_pair(ai, bi), make_pair(ci, di)));
        specialPhotos[i].push_back(make_pair(ei, 0));
    }

    int minDistance = INT_MAX;
    for (int i = 0; i < k; i++) {
        int totalDistance = 0;
        for (int j = 0; j < k; j++) {
            if (i != j) {
                int distance = 0;
                for (auto coord : specialPhotos[i]) {
                    int x1 = coord.first.first - 1;
                    int y1 = coord.first.second - 1;
                    int x2 = coord.second.first - 1;
                    int y2 = coord.second.second - 1;
                    char letter = coord.second.first;
                    distance += abs(templatePhoto[x1][y1] - letter);
                    for (int x = x1; x <= x2; x++) {
                        for (int y = y1; y <= y2; y++) {
                            distance += abs(templatePhoto[x][y] - letter);
                        }
                    }
                }
                totalDistance += distance;
            }
        }
        minDistance = min(minDistance, totalDistance);
    }

    cout << minDistance << endl;

    return 0;
}