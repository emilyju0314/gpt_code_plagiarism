#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;
    
    vector<int> houses(N);
    for(int i = 0; i < N; i++) {
        cin >> houses[i];
    }
    
    sort(houses.begin(), houses.end());
    
    int min_distance = 0;
    for(int i = 1; i < N; i++) {
        min_distance += houses[i] - houses[i-1];
    }
    
    min_distance += max(houses[N-1] - houses[0], houses[N-1] - houses[N-2]);
    
    cout << min_distance << endl;
    
    return 0;
}