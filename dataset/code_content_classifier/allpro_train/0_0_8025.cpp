#include <iostream>
#include <cmath>
#include <algorithm>
#include <climits>
using namespace std;

int main() {
    string n;
    cin >> n;

    int min_operations = INT_MAX;

    for(int i = 0; i < (1 << n.length()); i++) {
        string new_num = "";
        for(int j = 0; j < n.length(); j++) {
            if(i & (1 << j)) {
                new_num += n[j];
            }
        }
        
        if(new_num[0] != '0') {
            int num = stoi(new_num);
            int sq = sqrt(num);
            if(sq * sq == num) { // Check if it's a perfect square
                min_operations = min(min_operations, (int)n.length() - (int)new_num.length());
            }
        }
    }

    if(min_operations == INT_MAX) {
        cout << -1 << endl;
    } else {
        cout << min_operations << endl;
    }

    return 0;
}