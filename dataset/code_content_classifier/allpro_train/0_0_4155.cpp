#include <iostream>
#include <string>

using namespace std;

int countFeasts(int N) {
    int count = 0;
    string target = "51-3";

    for (int i = 0; i <= N; i++) {
        string number = to_string(i);
        if (number.find(target) != string::npos) {
            count++;
        }
    }

    return count;
}

int main() {
    int N;
    cin >> N;

    int result = countFeasts(N);
    cout << result << endl;

    return 0;
}