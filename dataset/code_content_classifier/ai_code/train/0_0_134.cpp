#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, k, p;
    cin >> n >> k >> p;

    vector<int> people(n);
    vector<int> keys(k);
    for(int i = 0; i < n; i++){
        cin >> people[i];
    }
    for(int i = 0; i < k; i++){
        cin >> keys[i];
    }

    sort(people.begin(), people.end());
    sort(keys.begin(), keys.end());

    int min_time = 2e9;
    for(int i = 0; i <= k-n; i++){
        int time = 0;
        for(int j = 0; j < n; j++){
            int dist = abs(people[j]-keys[i+j]) + abs(keys[i+j]-p);
            time = max(time, dist);
        }
        min_time = min(min_time, time);
    }

    cout << min_time << endl;

    return 0;
}