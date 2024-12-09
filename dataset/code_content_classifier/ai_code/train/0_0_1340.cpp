#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<pair<int, int>> firstSemifinal(n);
    vector<pair<int, int>> secondSemifinal(n);
    
    for (int i = 0; i < n; i++) {
        cin >> firstSemifinal[i].first >> secondSemifinal[i].first;
        firstSemifinal[i].second = secondSemifinal[i].second = i;
    }
    
    sort(firstSemifinal.begin(), firstSemifinal.end());
    sort(secondSemifinal.begin(), secondSemifinal.end());
    
    int k = 0;
    vector<int> res1(n, 0);
    vector<int> res2(n, 0);
    
    for (int i = 0; i < k; i++) {
        res1[firstSemifinal[i].second] = 1;
        res2[secondSemifinal[i].second] = 1;
    }
    
    for (int i = k; i < n - k; i++) {
        res1[firstSemifinal[i].second] = 1;
        res2[secondSemifinal[i].second] = 1;
    }
    
    for (int i = n - k; i < n; i++) {
        res1[firstSemifinal[i].second] = 0;
        res2[secondSemifinal[i].second] = 0;
    }
    
    for (int i = 0; i < n; i++) {
        cout << res1[i];
    }
    cout << endl;
    
    for (int i = 0; i < n; i++) {
        cout << res2[i];
    }
    cout << endl;
    
    return 0;
}