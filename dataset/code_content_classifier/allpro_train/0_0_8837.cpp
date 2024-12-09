#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    
    vector<int> damage(n);
    for(int i = 0; i < n; i++){
        cin >> damage[i];
    }
    
    string sequence;
    cin >> sequence;
    
    long long totalDamage = 0;
    vector<long long> maxDamage(26, 0);
    for(int i = 0; i < n; i++){
        int button = sequence[i] - 'a';
        maxDamage[button] = max(maxDamage[button], 0LL) + damage[i];
        totalDamage = max(totalDamage, maxDamage[button]);
        if(i >= k){
            int prevButton = sequence[i - k] - 'a';
            maxDamage[prevButton] = max(maxDamage[prevButton] - damage[i - k], 0LL);
        }
    }
    
    cout << totalDamage << endl;

    return 0;
}