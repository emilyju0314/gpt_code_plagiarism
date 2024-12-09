#include <iostream>
#include <vector>
using namespace std;

bool isPossible(int n, int d, int b, vector<int>& students) {
    int rooms1 = 0, rooms2 = 0;

    int left = 0, right = n - 1;
    while (left <= right) {
        int max_rooms = max(rooms1, rooms2);
        if (max_rooms * b >= students[left] && max_rooms * b >= students[right]) {
            return true;
        }

        if (students[left] < b) {
            rooms1++;
        } else {
            rooms1 = 0;
        }

        if (students[right] < b) {
            rooms2++;
        } else {
            rooms2 = 0;
        }

        left++;
        right--;
    }

    return false;
}

int main() {
    int n, d, b;
    cin >> n >> d >> b;

    vector<int> students(n);
    for (int i = 0; i < n; i++) {
        cin >> students[i];
    }

    int left = 0, right = n;
    int ans = n;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (isPossible(n, d, b, students)) {
            ans = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    cout << ans << endl;

    return 0;
}