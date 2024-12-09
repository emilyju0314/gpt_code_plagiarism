#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Car {
    int index;
    int time;

    Car(int i, int t) {
        index = i;
        time = t;
    }

    bool operator<(const Car& other) const {
        if (time != other.time) {
            return time > other.time; // Min heap based on time
        } else {
            return index > other.index; // Min heap based on index
        }
    }
};

int main() {
    int m, n;
    
    while (true) {
        cin >> m >> n;

        if (m == 0 && n == 0) {
            break;
        }

        vector<int> parkingTimes(n);
        for (int i = 0; i < n; i++) {
            cin >> parkingTimes[i];
        }

        priority_queue<Car> pq;
        vector<int> result;

        priority_queue<int, vector<int>, greater<int>> availableSpaces;
        for (int i = 1; i <= m; i++) {
            availableSpaces.push(i);
        }

        int currentTime = 0;

        for (int i = 0; i < n; i++) {
            currentTime += 10;

            // Check if any cars need to be removed
            while (!pq.empty() && pq.top().time <= currentTime) {
                availableSpaces.push(pq.top().index);
                pq.pop();
            }

            if (availableSpaces.empty()) {
                // No available parking spaces, waiting for the next car to be removed
                currentTime = pq.top().time;
                i--;
                continue;
            }

            int parkingSpace = availableSpaces.top();
            availableSpaces.pop();
            pq.push(Car(parkingSpace, currentTime + parkingTimes[i]));
            result.push_back(i + 1);
        }

        for (int i = 0; i < n; i++) {
            cout << result[i];
            if (i < n - 1) {
                cout << " ";
            }
        }
        cout << endl;
    }

    return 0;
}