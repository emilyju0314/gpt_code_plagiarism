#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;
    
    vector<int> cash(N);
    for(int i = 0; i < N; i++) {
        cin >> cash[i];
    }
    
    sort(cash.begin(), cash.end());
    
    int maxProducts = 0;
    for(int i = 0; i < N; i++) {
        if(cash[i] >= maxProducts + 1) {
            maxProducts++;
        }
    }
    
    cout << maxProducts << endl;
    
    return 0;
}