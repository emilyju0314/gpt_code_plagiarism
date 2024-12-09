#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Dancer {
    int group;
    int position;
    int waiting_time;
};

int main() {
    int n, w, h;
    cin >> n >> w >> h;

    vector<Dancer> dancers(n);
    for (int i = 0; i < n; i++) {
        cin >> dancers[i].group >> dancers[i].position >> dancers[i].waiting_time;
    }

    vector<int> positions(n);
    for (int i = 0; i < n; i++) {
        if (dancers[i].group == 1) {
            positions[i] = dancers[i].position + dancers[i].waiting_time;
        } else {
            positions[i] = dancers[i].position - dancers[i].waiting_time;
        }
    }

    for (int i = 0; i < n; i++) {
        if (dancers[i].group == 1) {
            cout << positions[i] % w << " " << h << endl;
        } else {
            cout << w << " " << positions[i] % h << endl;
        }
    }

    return 0;
}