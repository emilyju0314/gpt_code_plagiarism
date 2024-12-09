#include <iostream>
#include <set>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    set<int> indexes;
    int temp;
    for (int i = 0; i < n; i++) {
        cin >> temp;
        indexes.insert(temp);
    }
    
    int defaultIndex = 1;
    while (indexes.count(defaultIndex) > 0) {
        defaultIndex++;
    }
    
    cout << defaultIndex << endl;
    
    return 0;
}