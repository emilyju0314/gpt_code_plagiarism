#include <iostream>
#include <set>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> elements(n);
    for(int i = 0; i < n; i++) {
        cin >> elements[i];
    }
    
    sort(elements.begin(), elements.end());
    
    set<int> distinct_diffs;
    for(int i = 0; i < n; i++) {
        for(int j = i+1; j < n; j++) {
            distinct_diffs.insert(abs(elements[i] - elements[j]));
        }
    }
    
    if(distinct_diffs.size() % 2 == 0) {
        cout << "Bob" << endl;
    } else {
        cout << "Alice" << endl;
    }
    
    return 0;
}