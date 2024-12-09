#include <iostream>
#include <set>

using namespace std;

int main() {
    int N;
    cin >> N;
    
    set<int> values;
    
    for(int i = 0; i < N; i++) {
        int value;
        cin >> value;
        values.insert(value);
    }
    
    cout << values.size() << endl;
    
    return 0;
}