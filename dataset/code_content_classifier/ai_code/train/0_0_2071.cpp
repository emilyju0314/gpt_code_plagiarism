#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() {
    int N;
    cin >> N;

    map<string, int> dictionary;
    for (int i = 0; i < N; i++) {
        string Sid;
        cin >> Sid;
        dictionary[Sid] = i + 1;
    }

    int Q;
    cin >> Q;

    for (int i = 0; i < Q; i++) {
        int k, id;
        cin >> k >> id;

        if (k == 1) {
            string Sid;
            cin >> Sid;
            dictionary[Sid] = id;
        } else if (k == 2) {
            string Sid;
            cin >> Sid;
            dictionary.erase(Sid);
        } else if (k == 3) {
            string Sid;
            cin >> Sid;

            int min_id = N + 1;
            int answer = -1;

            for (auto it = dictionary.begin(); it != dictionary.end(); it++) {
                if (Sid.find(it->first) == 0 && it->second < min_id) {
                    min_id = it->second;
                    answer = it->second;
                }
            }

            cout << (answer == -1 ? -1 : answer) << endl;
        }
    }

    return 0;
}