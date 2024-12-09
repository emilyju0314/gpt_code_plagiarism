#include <iostream>
#include <vector>

using namespace std;

int main() {
    long long T;
    int N;
    cin >> T >> N;
    
    vector<pair<long long, long long>> schedule;
    
    for(int i = 0; i < N; i++) {
        long long s, t;
        cin >> s >> t;
        schedule.push_back({s, t});
    }
    
    long long maxEffect = 0;
    long long prevEnd = 0;
    
    for(int i = 0; i < N; i++) {
        long long start = schedule[i].first;
        long long end = schedule[i].second;

        if(start > prevEnd) {
            maxEffect += min(T, end - start);
        } else {
            maxEffect += min(T, end - prevEnd);
        }

        prevEnd = end;
    }

    cout << maxEffect << endl;

    return 0;
}