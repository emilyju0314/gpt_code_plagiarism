#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int main() {
    int N, K;
    cin >> N;
    
    vector<pair<long long, long long>> ranges(N);
    for(int i = 0; i < N; i++) {
        cin >> ranges[i].first >> ranges[i].second;
    }
    
    cin >> K;

    long long count = 0;
    for(int i = 0; i < N; i++) {
        for(long long j = ranges[i].first; j <= ranges[i].second; j++) {
            if(to_string(j)[0] == '1') {
                count++;
                break;
            }
        }
    }

    double probability = 0.0;
    if(count * 100 >= N * K) {
        probability = 1.0;
    } else {
        probability = 1.0 - pow(0.9, N);
    }

    cout << fixed << setprecision(15) << probability << endl;

    return 0;
}