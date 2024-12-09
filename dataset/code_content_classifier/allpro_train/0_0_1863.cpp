#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> powers(n);
    for(int i = 0; i < n; i++) {
        cin >> powers[i];
    }

    long long count = 0;
    for(int i = 1; i < n-1; i++) {
        int left_smaller = 0;
        int right_greater = 0;

        for(int j = 0; j < i; j++) {
            if(powers[j] < powers[i]) {
                left_smaller++;
            }
        }

        for(int k = i+1; k < n; k++) {
            if(powers[k] > powers[i]) {
                right_greater++;
            }
        }

        count += left_smaller * right_greater;
    }

    cout << count << endl;

    return 0;
}