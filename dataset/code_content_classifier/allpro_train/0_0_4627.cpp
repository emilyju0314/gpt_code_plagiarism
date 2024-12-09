#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    unordered_map<int, int> countLeft, countRight;
    long long answer = 0;

    for (int i = 0; i < n; i++) {
        countRight[a[i]]++;
    }

    for (int i = 0; i < n; i++) {
        countRight[a[i]]--;
        answer += countLeft[a[i]] * countRight[a[i]];
        countLeft[a[i]]++;
    }

    cout << answer << endl;

    return 0;
}