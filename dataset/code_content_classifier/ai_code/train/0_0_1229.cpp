#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> contests(n);
    for(int i = 0; i < n; i++) {
        cin >> contests[i];
    }
    
    sort(contests.begin(), contests.end());
    
    int days = 0;
    int currentDay = 1;
    
    for(int i = 0; i < n; i++) {
        if(contests[i] >= currentDay) {
            days++;
            currentDay++;
        }
    }
    
    cout << days << endl;
    
    return 0;
}