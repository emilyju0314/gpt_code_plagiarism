#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

struct Participant {
    int number;
    double height;
};

int main() {
    int n, t1, t2, k;
    cin >> n >> t1 >> t2 >> k;

    vector<Participant> participants(n);

    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;

        double height1 = a * t1 * (1 - k / 100.0) + b * t2;
        double height2 = b * t1 * (1 - k / 100.0) + a * t2;

        participants[i].number = i + 1;
        participants[i].height = max(height1, height2);
    }

    sort(participants.begin(), participants.end(), [](const Participant& p1, const Participant& p2){
        if (p1.height == p2.height) {
            return p1.number < p2.number;
        }
        return p1.height > p2.height;
    });

    cout << fixed << setprecision(2);
    for (Participant p : participants) {
        cout << p.number << " " << p.height << endl;
    }

    return 0;
}