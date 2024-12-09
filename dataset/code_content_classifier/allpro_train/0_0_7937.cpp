#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, a, b, c, d, start, len;
    cin >> n >> a >> b >> c >> d >> start >> len;

    vector<pair<int, int>> events(n);
    for(int i = 0; i < n; i++) {
        cin >> events[i].first >> events[i].second;
    }

    // Check if Izabella's rating will become negative before or during the influence of the talk show
    int current_rating = start;
    int negative_time = -1;
    for(int i = 0; i < n; i++) {
        if(events[i].second == 0) {
            current_rating -= b;
        } else {
            current_rating += a;
        }

        if(current_rating < 0) {
            negative_time = events[i].first;
            break;
        }
    }

    if(negative_time != -1) {
        // Find a suitable moment for the talk show
        bool found_suitable_time = false;
        for(int i = 0; i < n; i++) {
            if(events[i].first >= negative_time) {
                int t = events[i].first - len;
                if(t >= 0) {
                    cout << t << endl;
                    found_suitable_time = true;
                    break;
                }
            }
        }

        if(!found_suitable_time) {
            cout << -1 << endl;
        }
    } else {
        cout << -1 << endl;
    }

    return 0;
}