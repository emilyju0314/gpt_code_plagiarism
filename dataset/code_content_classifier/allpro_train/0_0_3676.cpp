#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct request {
    int idx, c, p;
};

bool compareRequests(request& r1, request& r2) {
    return r1.p > r2.p;
}

int main() {
    int n;
    cin >> n;

    vector<request> requests(n);
    for (int i = 0; i < n; i++) {
        cin >> requests[i].c >> requests[i].p;
        requests[i].idx = i + 1;
    }

    int k;
    cin >> k;
    vector<int> tables(k);
    for (int i = 0; i < k; i++) {
        cin >> tables[i];
    }

    sort(requests.begin(), requests.end(), compareRequests);

    int m = 0, s = 0;
    vector<pair<int, int>> acceptedRequests;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < k; j++) {
            if (requests[i].c <= tables[j]) {
                acceptedRequests.push_back({requests[i].idx, j + 1});
                m++;
                s += requests[i].p;
                tables[j] -= requests[i].c;
                break;
            }
        }
    }

    cout << m << " " << s << endl;
    for (auto it : acceptedRequests) {
        cout << it.first << " " << it.second << endl;
    }

    return 0;
}