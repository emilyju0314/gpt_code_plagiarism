#include<bits/stdc++.h>
using namespace std;

int main() {
    long long ts, tf, t;
    cin >> ts >> tf >> t;

    int n;
    cin >> n;

    vector<long long> visitors(n);
    for (int i = 0; i < n; i++) {
        cin >> visitors[i];
    }

    if (n == 0) {
        cout << ts << endl;
        return 0;
    }

    long long best_time = -1;
    long long best_wait = LLONG_MAX;

    for (int i = 0; i < n; i++) {
        if (visitors[i] > tf - t) {
            long long arrival_time = visitors[i] - t;

            if (best_wait > (arrival_time - ts) || best_wait == arrival_time - ts && best_time < arrival_time) {
                best_time = arrival_time;
                best_wait = arrival_time - ts;
            }
        } else {
            long long arrival_time = visitors[i] - t;
            if (best_wait > (arrival_time - ts) || best_wait == arrival_time - ts && best_time < arrival_time) {
                best_time = arrival_time;
                best_wait = arrival_time - ts;
            }
        }
    }

    if (best_time == -1 || best_time < ts) {
        cout << ts << endl;
    } else {
        cout << best_time << endl;
    }

    return 0;
}