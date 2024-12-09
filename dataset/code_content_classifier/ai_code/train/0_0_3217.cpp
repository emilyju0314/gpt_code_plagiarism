#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(pair<int, int>& a, pair<int, int>& b) {
    return a.second < b.second;
}

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> venueA(n);
    vector<pair<int, int>> venueB(n);

    for (int i = 0; i < n; i++) {
        int sa, ea, sb, eb;
        cin >> sa >> ea >> sb >> eb;
        venueA[i] = make_pair(sa, ea);
        venueB[i] = make_pair(sb, eb);
    }

    sort(venueA.begin(), venueA.end(), compare);
    sort(venueB.begin(), venueB.end(), compare);

    int maxEndingA = 0;
    int maxEndingB = 0;

    for (int i = 0; i < n; i++) {
        if (venueA[i].first > maxEndingA) {
            maxEndingA = venueA[i].second;
        } else if (venueB[i].first > maxEndingA) {
            maxEndingA = venueB[i].second;
        }

        if (venueB[i].first > maxEndingB) {
            maxEndingB = venueB[i].second;
        } else if (venueA[i].first > maxEndingB) {
            maxEndingB = venueA[i].second;
        }
    }

    if (maxEndingA < maxEndingB || maxEndingB < maxEndingA) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}