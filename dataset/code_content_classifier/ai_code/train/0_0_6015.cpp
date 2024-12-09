#include <iostream>
#include <vector>

using namespace std;

int countOperations(vector<int>& towers) {
    int operations = 0;
    
    for(int i = 0; i < towers.size(); i++) {
        if(i == 0) {
            operations += 1;
        } else {
            operations += abs(towers[i] - towers[i-1]);
        }
    }
    
    return operations;
}

int main() {
    int n;
    cin >> n;
    
    vector<int> towers(n);
    for(int i = 0; i < n; i++) {
        cin >> towers[i];
    }
    
    int result = countOperations(towers);
    cout << result << endl;
    
    return 0;
}