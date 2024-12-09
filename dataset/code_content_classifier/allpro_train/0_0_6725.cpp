#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> flowers(n);
    int oddCount = 0, evenCount = 0;

    for(int i = 0; i < n; i++) {
        cin >> flowers[i];
        if(flowers[i] % 2 == 0) {
            evenCount++;
        } else {
            oddCount++;
        }
    }

    int result = 0;

    if(oddCount % 2 == 0) {
        result = evenCount;
    } else {
        result = min(oddCount, evenCount);
    }

    cout << result << endl;

    return 0;
}