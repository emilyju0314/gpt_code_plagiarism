#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> strengths(n);
    for(int i = 0; i < n; i++) {
        cin >> strengths[i];
    }
    
    string teams;
    cin >> teams;
    
    long long total_sum = 0;
    
    for(int i = 0; i < n; i++) {
        total_sum += strengths[i];
    }
    
    long long max_sum = 0;
    long long current_sum = 0;
    
    for(int i = 0; i < n; i++) {
        if(teams[i] == 'B') {
            current_sum += strengths[i];
        }
    }
    
    max_sum = max(max_sum, total_sum - current_sum);
    current_sum = 0;
    
    for(int i = n-1; i >= 0; i--) {
        if(teams[i] == 'B') {
            current_sum += strengths[i];
        }
        max_sum = max(max_sum, total_sum - current_sum);
    }
    
    cout << max_sum << endl;
    
    return 0;
}