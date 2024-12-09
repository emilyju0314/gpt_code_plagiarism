#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    int n, vb, vs;
    cin >> n >> vb >> vs;

    vector<int> stops(n);
    for(int i = 0; i < n; i++) {
        cin >> stops[i];
    }

    int xu, yu;
    cin >> xu >> yu;

    double minTime = 1e9;
    int optimalStop = 1;

    for(int i = 1; i < n - 1; i++) {
        double timeToStop = stops[i] / (double)vb;
        double totalDistance = sqrt(pow(stops[i] - xu, 2) + pow(yu, 2));
        double timeToUni = totalDistance / (double)vs;
        double totalTime = timeToStop + timeToUni;

        if(totalTime < minTime) {
            minTime = totalTime;
            optimalStop = i + 1;
        }
    }

    cout << optimalStop << endl;

    return 0;
}