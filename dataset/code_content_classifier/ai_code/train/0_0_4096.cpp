#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, a, b;
    cin >> n >> a >> b;
    
    vector<int> chores(n);
    for(int i = 0; i < n; i++) {
        cin >> chores[i];
    }
    
    sort(chores.begin(), chores.end());
    
    int petyaChores = 0;
    int vasyaChores = 0;
    int possibleXValues = 0;
    
    for(int i = 0; i < n; i++) {
        if(i < a) {
            petyaChores += chores[i];
        } else {
            vasyaChores += chores[i];
        }
    }
    
    if(a == 0 || b == 0) {
        cout << "0" << endl;
    } else if (petyaChores % a == 0 && vasyaChores % b == 0) {
        int x = chores[a-1];
        if (x == chores[a]) {
            possibleXValues = 1;
            cout << possibleXValues << endl;
        } else {
            possibleXValues = chores[a] - chores[a-1];
            cout << possibleXValues << endl;
        }
    } else {
        cout << "0" << endl;
    }
    
    return 0;
}