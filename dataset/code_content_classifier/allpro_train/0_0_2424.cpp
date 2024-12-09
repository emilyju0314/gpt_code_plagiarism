#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

double euclideanDistance(pair<int, int> a, pair<int, int> b) {
    return sqrt(pow(a.first - b.first, 2) + pow(a.second - b.second, 2));
}

double calculateShortestDistance(pair<pair<int, int>, pair<int, int>> a, pair<pair<int, int>, pair<int, int>> b) {
    double directDistance = euclideanDistance(a.first, b.first) + euclideanDistance(a.second, b.second);
    double indirectDistance = euclideanDistance(a.first, b.second) + euclideanDistance(a.second, b.first);
    return min(directDistance, indirectDistance);
}

int main() {
    int NA, NB;
    cin >> NA >> NB;

    vector<pair<int, int>> Totata(NA);
    vector<pair<int, int>> Tutete(NB);

    for (int i = 0; i < NA; i++) {
        cin >> Totata[i].first >> Totata[i].second;
    }

    for (int i = 0; i < NB; i++) {
        cin >> Tutete[i].first >> Tutete[i].second;
    }

    double minTotalLength = -1;

    for (int i = 0; i < NA; i++) {
        for (int j = 0; j < NB; j++) {
            for (int k = i + 1; k < NA; k++) {
                for (int l = j + 1; l < NB; l++) {
                    double totalLength = calculateShortestDistance({Totata[i], Totata[k]}, {Tutete[j], Tutete[l]});
                    if (minTotalLength == -1 || totalLength < minTotalLength) {
                        minTotalLength = totalLength;
                    }
                }
            }
        }
    }

    cout << fixed << minTotalLength << endl;

    return 0;
}