#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> bars(n);
    for (int i = 0; i < n; i++) {
        cin >> bars[i];
    }
    
    int left = 0, right = n - 1;
    int aliceBars = 0, bobBars = 0;
    int aliceTime = 0, bobTime = 0;
    
    while (left <= right) {
        if (aliceTime <= bobTime) {
            aliceTime += bars[left];
            aliceBars++;
            left++;
        } else {
            bobTime += bars[right];
            bobBars++;
            right--;
        }
    }
    
    cout << aliceBars << " " << bobBars << endl;
    
    return 0;
}