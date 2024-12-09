#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> interesting_minutes(n);
    for(int i = 0; i < n; i++) {
        cin >> interesting_minutes[i];
    }

    int watched_minutes = 0;
    int last_watched_minute = 0;

    for(int i = 0; i < n; i++) {
        if(interesting_minutes[i] - last_watched_minute >= 15) {
            watched_minutes = last_watched_minute + 15;
            break;
        }
        
        last_watched_minute = interesting_minutes[i];
    }

    if(watched_minutes == 0) {
        watched_minutes = min(interesting_minutes[n-1] + 15, 90);
    }

    cout << watched_minutes << endl;

    return 0;
}