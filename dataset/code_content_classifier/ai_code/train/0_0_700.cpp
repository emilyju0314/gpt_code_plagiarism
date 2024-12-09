#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> sequence(n);
    for(int i = 0; i < n; i++) {
        cin >> sequence[i];
    }
    
    long long negativeCount = 0, positiveCount = 0;
    long long negative = 0, positive = 0, product = 1;
    
    for(int i = 0; i < n; i++) {
        product *= sequence[i];
        
        if(product < 0) {
            negativeCount += negative + (positive + 1);
            negative++;
        } else {
            positiveCount += negative + (positive + 1);
            positive++;
        }
    }
    
    cout << negativeCount << " " << positiveCount << endl;
    
    return 0;
}