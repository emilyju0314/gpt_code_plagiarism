#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct Alpinist {
    int skill;
    int neatness;
};

bool compareNeatness(const Alpinist& a, const Alpinist& b) {
    return a.neatness > b.neatness;
}

int main() {
    int n, d;
    cin >> n >> d;

    vector<Alpinist> alpinists(n);
    for (int i = 0; i < n; i++) {
        cin >> alpinists[i].skill >> alpinists[i].neatness;
    }

    // Sort alpinists based on neatness in descending order
    sort(alpinists.begin(), alpinists.end(), compareNeatness);

    priority_queue<int> pq;
    int count = 0;

    for (int i = 0; i < n; i++) {
        while (!pq.empty() && pq.top() >= d) {
            pq.pop();
        }

        if (alpinists[i].skill >= d) {
            count++;
        } else {
            pq.push(alpinists[i].skill);
        }

        d = max(d, alpinists[i].neatness);
    }

    cout << count << endl;

    return 0;
}