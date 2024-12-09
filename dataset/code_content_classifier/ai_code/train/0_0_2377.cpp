#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    int max_length = 2; // minimum length of a good segment
    
    for (int i = 2; i < n; i++) {
        if (a[i] == a[i - 1] + a[i - 2]) {
            int length = 3;
            int j = i + 1;
            while (j < n && a[j] == a[j - 1] + a[j - 2]) {
                length++;
                j++;
            }
            max_length = max(max_length, length);
        }
    }
    
    cout << max_length << endl;

    return 0;
}