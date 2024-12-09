#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Alpinist {
    int skill;
    int neatness;
};

bool compare(Alpinist a, Alpinist b) {
    return a.skill > b.skill;
}

int main() {
    int n, d;
    cin >> n >> d;

    vector<Alpinist> alpinists(n);
    for (int i = 0; i < n; i++) {
        cin >> alpinists[i].skill >> alpinists[i].neatness;
    }

    sort(alpinists.begin(), alpinists.end(), compare);

    int maxAlpinists = 0;
    for (int i = 0; i < n; i++) {
        if (d <= alpinists[i].skill) {
            d = max(d, alpinists[i].neatness);
            maxAlpinists++;
        }
    }

    cout << maxAlpinists << endl;

    return 0;
}