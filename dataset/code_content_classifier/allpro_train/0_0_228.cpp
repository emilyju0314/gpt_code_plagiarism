#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<long long, long long>> beams;
int n;

bool check(long long mid) {
    vector<long long> ranges(n);
    for (int i = 0; i < n; i++) {
        ranges[i] = beams[i].first - mid * beams[i].second;
    }
    sort(ranges.begin(), ranges.end());
    
    long long sum = 0;
    for (int i = n/2; i < n; i++) {
        sum += ranges[i];
    }
    
    return sum >= 0;
}

int main() {
    cin >> n;
    beams.resize(n);
    
    for (int i = 0; i < n; i++) {
        cin >> beams[i].first >> beams[i].second;
    }
    
    long long left = 0, right = 1e18;
    
    while (right - left > 1) {
        long long mid = (left + right) / 2;
        
        if (check(mid)) {
            left = mid;
        } else {
            right = mid;
        }
    }
    
    cout << left / __gcd(left, n) << " " << n / __gcd(left, n) << endl;
    
    return 0;
}