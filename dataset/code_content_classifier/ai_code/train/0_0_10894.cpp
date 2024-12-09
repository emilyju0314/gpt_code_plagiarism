#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N;
    cin >> N;
    
    vector<int> sticks(N);
    for(int i = 0; i < N; i++) {
        cin >> sticks[i];
    }
    
    sort(sticks.begin(), sticks.end(), greater<int>());
    
    long long max_area = 0;
    for(int i = 0; i < N-1; i++) {
        if(sticks[i] == sticks[i+1]) {
            max_area = (long long)sticks[i] * sticks[i+1];
            break;
        }
    }
    
    cout << max_area << endl;
    
    return 0;
}