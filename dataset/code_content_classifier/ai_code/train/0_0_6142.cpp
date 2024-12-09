#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main() {
    int N, Q;
    cin >> N >> Q;

    struct Request {
        int a, b, p;
    };

    vector<Request> requests(Q);
    for(int i = 0; i < Q; i++) {
        cin >> requests[i].a >> requests[i].b >> requests[i].p;
    }

    priority_queue<pair<int, int>> pq;
    int current_pos = 1;
    long long time = 0;

    for(int i = 0; i < Q; i++) {
        while(!pq.empty() && current_pos < requests[i].a) {
            time += pq.top().first - current_pos;
            current_pos = pq.top().second;
            pq.pop();
        }

        if(current_pos == requests[i].a) {
            time += requests[i].p;
            pq.push({current_pos + requests[i].p, requests[i].b});
            current_pos += requests[i].p;
        } else {
            pq.push({current_pos + (requests[i].a - current_pos) + requests[i].p, requests[i].b});
            current_pos = requests[i].a + requests[i].p;
            time += current_pos - requests[i].a;
        }

        cout << time << endl;
    }

    return 0;
}