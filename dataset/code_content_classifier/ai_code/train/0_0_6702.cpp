#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, k, w;
    cin >> n >> k >> w;
    
    string boxes;
    cin >> boxes;
    
    vector<int> candies(n);
    for (int i = 0; i < n; i++) {
        candies[i] = boxes[i] - '0';
    }
    
    vector<int> prefixSum(n);
    prefixSum[0] = candies[0];
    for (int i = 1; i < n; i++) {
        prefixSum[i] = prefixSum[i-1] + candies[i];
    }
    
    for (int i = 0; i < w; i++) {
        int li, ri;
        cin >> li >> ri;
        
        int numBoxes = (ri - li + 1) / k;
        int numCandies = (li - 1) / k;
        
        int totalCandies = prefixSum[ri - 1] - (li > 1 ? prefixSum[li - 2] : 0);
        int neededCandies = numBoxes - totalCandies;
        
        cout << neededCandies << endl;
    }
    
    return 0;
}