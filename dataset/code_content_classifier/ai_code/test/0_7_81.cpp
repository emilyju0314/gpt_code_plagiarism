#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Alpinist {
    int skill;
    int neetness;
};

bool compareAlpinists(const Alpinist& a, const Alpinist& b) {
    return a.neetness > b.neetness;
}

int main() {
    int n, d;
    cin >> n >> d;

    vector<Alpinist> alpinists(n);
    for (int i = 0; i < n; i++) {
        cin >> alpinists[i].skill >> alpinists[i].neetness;
    }

    sort(alpinists.begin(), alpinists.end(), compareAlpinists);

    int maxAlpinists = 0;
    for (const Alpinist& alpinist : alpinists) {
        if (alpinist.skill >= d) {
            d = max(d, alpinist.neetness);
            maxAlpinists++;
        }
    }

    cout << maxAlpinists << endl;

    return 0;
}