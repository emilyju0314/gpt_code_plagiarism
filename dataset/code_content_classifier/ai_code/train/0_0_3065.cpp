#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> years(n-1);
    for (int i = 0; i < n-1; i++) {
        cin >> years[i];
    }
    
    int a, b;
    cin >> a >> b;
    
    int totalYears = 0;
    for (int i = a; i < b; i++) {
        totalYears += years[i-1];
    }
    
    cout << totalYears << endl;
    
    return 0;
}