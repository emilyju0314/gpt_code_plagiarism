#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Alpinist {
    int skill;
    int neatness;
};

bool compareAlpinists(const Alpinist &a1, const Alpinist &a2) {
    return a1.neatness > a2.neatness;
}

int main() {
    int n, d;
    cin >> n >> d;

    vector<Alpinist> alpinists(n);
    for (int i = 0; i < n; i++) {
        cin >> alpinists[i].skill >> alpinists[i].neatness;
    }

    sort(alpinists.begin(), alpinists.end(), compareAlpinists);

    int maxAlpinists = 0;
    int currentDifficulty = d;

    for (int i = 0; i < n; i++) {
        if (alpinists[i].skill >= currentDifficulty) {
            maxAlpinists++;
            currentDifficulty = max(currentDifficulty, alpinists[i].neatness);
        }
    }

    cout << maxAlpinists << endl;

    return 0;
}