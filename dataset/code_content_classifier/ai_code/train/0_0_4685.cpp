#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    int min_capacity = 0;
    int current_capacity = 0;
    for(int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        
        current_capacity = current_capacity - a + b;
        min_capacity = max(min_capacity, current_capacity);
    }

    cout << min_capacity << endl;

    return 0;
}