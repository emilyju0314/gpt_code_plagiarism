#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> arr(n);
    vector<int> gaps;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        if (arr[i] == -1) {
            gaps.push_back(i);
        }
    }
    
    int m;
    cin >> m;
    
    vector<int> fill(m);
    for (int i = 0; i < m; i++) {
        cin >> fill[i];
    }
    
    sort(fill.begin(), fill.end());
    
    int index = 0;
    for (int gap : gaps) {
        arr[gap] = fill[index++];
    }
    
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    
    return 0;
}