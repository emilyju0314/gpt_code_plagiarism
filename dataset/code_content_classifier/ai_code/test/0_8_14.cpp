#include <iostream>
#include <vector>

using namespace std;

void cyclicSort(vector<int>& arr) {
    vector<pair<int, int>> actions;
    
    for (int i = 0; i < arr.size(); i++) {
        int minIndex = i;
        for (int j = i+1; j < arr.size(); j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        
        if (minIndex != i) {
            int d = minIndex - i;
            actions.push_back({i+1, minIndex+1, d});
            rotate(arr.begin() + i, arr.begin() + minIndex, arr.begin() + minIndex + 1);
        }
    }
    
    cout << actions.size() << endl;
    for (auto action : actions) {
        cout << action.first << " " << action.second << " " << action.second - action.first << endl;
    }
}

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        
        cyclicSort(arr);
    }
    
    return 0;
}