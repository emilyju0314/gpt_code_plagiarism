#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, p;
    cin >> n >> p;

    vector<int> t(n);
    for(int i = 0; i < n; i++) {
        cin >> t[i];
    }

    vector<int> result(n);
    int currTime = 0;
    vector<int> queue;
    int nextAvailableTime = 0;

    for(int i = 0; i < n; i++) {
        if(t[i] < nextAvailableTime) {
            result[i] = nextAvailableTime;
            nextAvailableTime += p;
        } else {
            currTime = max(currTime, t[i]);
            result[i] = currTime;
            nextAvailableTime = currTime + p;
        }
    }

    for(int i = 0; i < n; i++) {
        cout << result[i] << " ";
    }

    return 0;
}