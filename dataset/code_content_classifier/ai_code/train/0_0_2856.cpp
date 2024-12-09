#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> cowWeights(n);
    for(int i = 0; i < n; i++) {
        cin >> cowWeights[i];
    }
    
    int p;
    cin >> p;
    
    for(int i = 0; i < p; i++) {
        int a, b;
        cin >> a >> b;
        
        long long totalMass = 0;
        for(int j = a-1; j < n; j += b) {
            totalMass += cowWeights[j];
        }
        
        cout << totalMass << endl;
    }
    
    return 0;
}