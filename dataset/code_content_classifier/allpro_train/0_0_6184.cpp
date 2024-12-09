#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> charisma(n);
    for(int i = 0; i < n; i++) {
        cin >> charisma[i];
    }
    
    int max_sum = 0;
    int current_sociability = 0;
    
    for(int i = 0; i < n - 1; i++) {
        current_sociability = max(current_sociability + charisma[i] - charisma[i+1], 0);
        max_sum = max(max_sum, current_sociability);
    }
    
    cout << max_sum << endl;
    
    return 0;
}