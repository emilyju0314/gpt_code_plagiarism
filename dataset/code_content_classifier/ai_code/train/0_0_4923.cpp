#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Guard {
    int id;
    int taskIndex;
    int timeLeft;
    vector<int> pattern;

    Guard(int _id, vector<int> _pattern) {
        id = _id;
        taskIndex = 0;
        timeLeft = _pattern[0];
        pattern = _pattern;
    }
};

int main() {
    int n, simDuration;
    while (true) {
        cin >> n >> simDuration;
        if (n == 0 && simDuration == 0) break;

        vector<Guard> guards;
        for (int i = 0; i < n; i++) {
            vector<int> pattern;
            int num;
            while (true) {
                cin >> num;
                if (num == 0) break;
                pattern.push_back(num);
            }
            guards.push_back(Guard(i + 1, pattern));
        }

        queue<int> waitQueue;
        int currentTime = 0;
        int totalWaitTime = 0;

        while (currentTime < simDuration) {
            for (Guard& guard : guards) {
                if (guard.timeLeft == 0) {
                    if (!waitQueue.empty() && waitQueue.front() == guard.id) {
                        waitQueue.pop();
                    }
                    guard.taskIndex++;
                    guard.taskIndex %= guard.pattern.size();
                    guard.timeLeft = guard.pattern[guard.taskIndex];
                }

                guard.timeLeft--;
                currentTime++;

                if (guard.timeLeft == 0) {
                    waitQueue.push(guard.id);
                }
            }

            if (!waitQueue.empty()) {
                totalWaitTime++;
                waitQueue.pop();
            }
        }

        cout << totalWaitTime << endl;
    }

    return 0;
}