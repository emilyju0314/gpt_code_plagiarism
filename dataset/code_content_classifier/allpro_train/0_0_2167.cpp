#include <iostream>
#include <vector>
#include <string>

using namespace std;

int countHappyPeople(const string& S, const vector<string>& people) {
    int count = 0;
    string recentChars = "";
    for (const string& person : people) {
        recentChars += person;
        if (recentChars.length() > S.length()) {
            recentChars = recentChars.substr(recentChars.length() - S.length());
        }
        if (recentChars == S) {
            count++;
        }
    }
    return count;
}

int main() {
    string S;
    cin >> S;

    int N, Q;
    cin >> N >> Q;

    vector<string> people(N);

    for (int i = 0; i < Q; i++) {
        int queryType;
        cin >> queryType;

        if (queryType == 1) {
            int l, r;
            string c;
            cin >> l >> r >> c;

            for (int j = l - 1; j <= r - 1; j++) {
                people[j] += c;
            }
        } else if (queryType == 2) {
            int l, r;
            cin >> l >> r;

            int happyCount = countHappyPeople(S, vector<string>(people.begin() + l - 1, people.begin() + r));
            cout << happyCount << endl;
        }
    }

    return 0;
}