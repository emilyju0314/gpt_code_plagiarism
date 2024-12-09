#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Student {
    int r, w;
};

bool compare(const Student &a, const Student &b) {
    return a.r - a.w < b.r - b.w;
}

int main() {
    int n, c, d;
    cin >> n >> c >> d;

    vector<Student> students(n);
    for (int i = 0; i < n; i++) {
        cin >> students[i].r >> students[i].w;
    }

    sort(students.begin(), students.end(), compare);

    long long count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                if ((students[i].r - c) * (students[j].w - d) > (students[j].r - c) * (students[i].w - d) &&
                    (students[j].r - c) * (students[k].w - d) > (students[k].r - c) * (students[j].w - d) &&
                    (students[k].r - c) * (students[i].w - d) > (students[i].r - c) * (students[k].w - d)) {
                    count++;
                }
            }
        }
    }

    cout << count << endl;

    return 0;
}