#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> students;
    for(int i = 1; i <= n; i += 2) {
        students.push_back(i);
    }
    for(int i = 2; i <= n; i += 2) {
        students.push_back(i);
    }

    cout << n << endl;
    for(int student : students) {
        cout << student << " ";
    }

    return 0;
}