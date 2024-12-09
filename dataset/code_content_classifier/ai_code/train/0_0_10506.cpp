#include <iostream>
#include <map>
using namespace std;

int main() {
    int n;
    cin >> n;

    map<int, int> memorySticks; // Map to keep track of memory sticks Bob currently has
    int earnings = 0;

    for (int i = 0; i < n; i++) {
        string event;
        int x;
        cin >> event >> x;

        if (event == "sell") {
            if (memorySticks.find(x) != memorySticks.end()) {
                earnings += 2*x;
                memorySticks.erase(x);
            }
        } else if (event == "win") {
            memorySticks[x]++;
        }
    }

    cout << earnings << endl;

    return 0;
}