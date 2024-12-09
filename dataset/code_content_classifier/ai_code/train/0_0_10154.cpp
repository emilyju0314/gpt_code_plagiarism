#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<long long> heights(n);
    for(int i = 0; i < n; i++) {
        cin >> heights[i];
    }

    for(int i = 0; i < n-1; i++) {
        while(heights[i] + 2 <= heights[i+1]) {
            heights[i]++;
            heights[i+1]--;
        }
    }

    for(int i = 0; i < n; i++) {
        cout << heights[i] << " ";
    }
    cout << endl;

    return 0;
}