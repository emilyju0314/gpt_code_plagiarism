#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct City {
    int prefecture;
    int year;
    int id;
};

bool compare(City& city1, City& city2) {
    return city1.year < city2.year;
}

int main() {
    int N, M;
    cin >> N >> M;

    vector<City> cities(M);

    for (int i = 0; i < M; i++) {
        cin >> cities[i].prefecture >> cities[i].year;
        cities[i].id = i;
    }

    sort(cities.begin(), cities.end(), compare);

    vector<int> count(N+1, 1);
    vector<string> IDs(M);

    for (int i = 0; i < M; i++) {
        int pref = cities[i].prefecture;
        int year = cities[i].year;
        int idx = count[pref]++;
        
        string prefStr = to_string(pref);
        while (prefStr.length() < 6) {
            prefStr = '0' + prefStr;
        }

        string idxStr = to_string(idx);
        while (idxStr.length() < 6) {
            idxStr = '0' + idxStr;
        }

        IDs[cities[i].id] = prefStr + idxStr;
    }

    for (int i = 0; i < M; i++) {
        cout << IDs[i] << endl;
    }

    return 0;
}