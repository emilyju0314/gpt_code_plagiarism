#include <iostream>
#include <vector>

using namespace std;

struct Meteor {
    int t1, x1, y1, t2, x2, y2;
};

int main() {
    int n;
    cin >> n;

    vector<Meteor> meteors(n);

    for (int i = 0; i < n; i++) {
        cin >> meteors[i].t1 >> meteors[i].x1 >> meteors[i].y1 >> meteors[i].t2 >> meteors[i].x2 >> meteors[i].y2;
    }

    int maxMeteors = 1;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if ((meteors[i].x1 - meteors[j].x1) * (meteors[i].y2 - meteors[j].y2) == (meteors[i].y1 - meteors[j].y1) * (meteors[i].x2 - meteors[j].x2)) {
                maxMeteors = max(maxMeteors, 2);
            }
        }
    }

    cout << maxMeteors << endl;

    return 0;
}