#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Competitor {
    int swimmingSpeed;
    int runningSpeed;
};

bool compare(Competitor a, Competitor b) {
    return a.runningSpeed < b.runningSpeed;
}

int main() {
    int n;
    cin >> n;

    vector<Competitor> competitors(n);
    for (int i = 0; i < n; i++) {
        cin >> competitors[i].swimmingSpeed >> competitors[i].runningSpeed;
    }

    sort(competitors.begin(), competitors.end(), compare);
    
    vector<int> possibleWinners;
    int maxRunningSpeed = competitors[0].runningSpeed;
    for (int i = 0; i < n; i++) {
        if (competitors[i].runningSpeed == maxRunningSpeed) {
            possibleWinners.push_back(i+1);
        }
    }

    for (int i = 0; i < possibleWinners.size(); i++) {
        cout << possibleWinners[i] << " ";
    }

    return 0;
}