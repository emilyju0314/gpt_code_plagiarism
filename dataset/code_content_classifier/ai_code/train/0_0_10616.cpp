#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Cup {
    int significance;
    int width;
};

bool compareCup(Cup a, Cup b) {
    return a.significance > b.significance;
}

int main() {
    int n, m, d;
    cin >> n >> m >> d;

    vector<Cup> physicsCups(n);
    vector<Cup> informaticsCups(m);

    for(int i = 0; i < n; i++) {
        cin >> physicsCups[i].significance >> physicsCups[i].width;
    }

    for(int i = 0; i < m; i++) {
        cin >> informaticsCups[i].significance >> informaticsCups[i].width;
    }

    sort(physicsCups.begin(), physicsCups.end(), compareCup);
    sort(informaticsCups.begin(), informaticsCups.end(), compareCup);

    int totalSignificance = 0;
    int physicsIndex = 0, informaticsIndex = 0;

    while(physicsIndex < n || informaticsIndex < m) {
        int widthLeft = d;
        int currentSignificance = 0;

        while(physicsIndex < n && informaticsIndex < m && widthLeft >= physicsCups[physicsIndex].width && widthLeft >= informaticsCups[informaticsIndex].width) {
            if(physicsCups[physicsIndex].significance >= informaticsCups[informaticsIndex].significance) {
                widthLeft -= physicsCups[physicsIndex].width;
                currentSignificance += physicsCups[physicsIndex].significance;
                physicsIndex++;
            } else {
                widthLeft -= informaticsCups[informaticsIndex].width;
                currentSignificance += informaticsCups[informaticsIndex].significance;
                informaticsIndex++;
            }
        }

        totalSignificance = max(totalSignificance, currentSignificance);
        if(physicsIndex < n && (informaticsIndex == m || widthLeft < informaticsCups[informaticsIndex].width)) {
            widthLeft -= physicsCups[physicsIndex].width;
            currentSignificance += physicsCups[physicsIndex].significance;
            physicsIndex++;
        } else if(informaticsIndex < m && (physicsIndex == n || widthLeft < physicsCups[physicsIndex].width)) {
            widthLeft -= informaticsCups[informaticsIndex].width;
            currentSignificance += informaticsCups[informaticsIndex].significance;
            informaticsIndex++;
        }

        totalSignificance = max(totalSignificance, currentSignificance);
    }

    cout << totalSignificance << endl;

    return 0;
}