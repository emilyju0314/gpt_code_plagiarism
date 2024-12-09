#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    long long sum = 0;
    vector<pair<long long, long long>> objects(n);
    for(int i = 0; i < n; i++) {
        cin >> objects[i].first >> objects[i].second;
        sum += objects[i].first;
    }

    long long s = 0;
    for(int i = 0; i < n; i++) {
        s |= objects[i].second;
    }

    // Check if the sum is negative and adjust s accordingly
    if(sum < 0) {
        for(int i = 0; i < 62; i++) {
            if(((s >> i) & 1) == 1) {
                s ^= (1LL << i);
                break;
            }
        }
    }

    cout << s << endl;

    return 0;
}