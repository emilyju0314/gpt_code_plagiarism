#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct Alpinist {
    int skill;
    int neatness;
};

bool compare(Alpinist& a, Alpinist& b) {
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

    priority_queue<int> pq;

    int maxAlpinists = 0;
    for (int i = 0; i < n; i++) {
        if (alpinists[i].skill >= d) {
            pq.push(alpinists[i].neatness);
            d = max(d, alpinists[i].neatness);
            maxAlpinists++;
        } else if (!pq.empty() && pq.top() >= d) {
            int topNeatness = pq.top();
            if (topNeatness > alpinists[i].neatness) {
                pq.pop();
                pq.push(alpinists[i].neatness);
                d = alpinists[i].neatness;
            }
        }
    }

    cout << maxAlpinists << endl;

    return 0;
}