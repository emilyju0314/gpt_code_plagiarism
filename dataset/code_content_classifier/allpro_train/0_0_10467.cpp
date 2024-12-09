#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int main() {
    int N, K;
    cin >> N >> K;

    priority_queue<int, vector<int>, greater<int>> pq;

    for (int i = 0; i < N; i++) {
        int arrive, leave;
        cin >> arrive;
        leave = arrive + 1;
        
        pq.push(arrive);
        pq.push(leave);
    }

    int matches = 0;
    int stove_on_time = 0;
    int current_visitors = 0;
    int last_event = pq.top();
    pq.pop();

    while (!pq.empty()) {
        int event = pq.top();
        pq.pop();

        stove_on_time += (event - last_event) * current_visitors;
        
        while (!pq.empty() && pq.top() == event) {
            current_visitors++;
            pq.pop();
        }
        
        last_event = event;

        if (current_visitors > 0 && matches < K) {
            stove_on_time++;
            matches++;
        }

        while (!pq.empty() && pq.top() == event) {
            current_visitors--;
            pq.pop();
        }
    }

    cout << stove_on_time << endl;

    return 0;
}