#include<bits/stdc++.h>
using namespace std;

int main() {
    long long H;
    int n;
    cin >> H >> n;
    
    vector<long long> d(n);
    for(int i=0; i<n; i++) {
        cin >> d[i];
    }
    
    long long sum = 0;
    long long first_negative_time = -1;
    
    for(int i=0; i<n; i++) {
        sum += d[i];
        if(sum <= 0 && first_negative_time == -1) {
            first_negative_time = i+1;
        }
    }
    
    if(first_negative_time == -1) {
        if(sum <= 0) {
            cout << n << endl;
        } else {
            cout << -1 << endl;
        }
    } else {
        long long cycles_needed = (H - sum) / abs(sum);
        long long total_time = cycles_needed * n + first_negative_time;
        if((H - sum) % abs(sum) != 0) {
            total_time += n;
        }
        cout << total_time << endl;
    }
    
    return 0;
}