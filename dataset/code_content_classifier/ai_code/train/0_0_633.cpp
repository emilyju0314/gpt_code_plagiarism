#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> arr(n);
    vector<int> firstSet, secondSet, thirdSet;
    
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    for(int i = 0; i < n; i++) {
        if(arr[i] < 0) {
            firstSet.push_back(arr[i]);
        } else if(arr[i] > 0) {
            secondSet.push_back(arr[i]);
        } else {
            thirdSet.push_back(arr[i]);
        }
    }
    
    cout << firstSet.size() << " ";
    for(int num : firstSet) {
        cout << num << " ";
    }
    cout << endl;
    
    cout << secondSet.size() << " ";
    for(int num : secondSet) {
        cout << num << " ";
    }
    cout << endl;
    
    cout << thirdSet.size() << " ";
    for(int num : thirdSet) {
        cout << num << " ";
    }
    cout << endl;
    
    return 0;
}