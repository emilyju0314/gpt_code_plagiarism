#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    map<string, string> likes;
    for (int i = 0; i < n; i++) {
        string p, like, q;
        cin >> p >> like >> q;
        likes[p] = q;
    }

    int a, b, c;
    cin >> a >> b >> c;

    vector<string> heroes = {"Anka", "Chapay", "Cleo", "Troll", "Dracul", "Snowy", "Hexadecimal"};

    // Initialize variables to store the minimum difference and the maximum total amount of liking
    int min_diff = max(a, max(b, c)) - min(a, min(b, c));
    int max_liking = 0;

    do {
        string team1 = heroes[0] + " " + heroes[1] + " " + heroes[2];
        string team2 = heroes[3] + " " + heroes[4];
        string team3 = heroes[5] + " " + heroes[6];

        int exp1 = a / 3;
        int exp2 = b / 2;
        int exp3 = c / 2;

        int diff = max(exp1, max(exp2, exp3)) - min(exp1, min(exp2, exp3);
        int team_liking = 0;

        if (likes[heroes[0]] == heroes[1] || likes[heroes[1]] == heroes[0]) team_liking++;
        if (likes[heroes[0]] == heroes[2] || likes[heroes[2]] == heroes[0]) team_liking++;
        if (likes[heroes[1]] == heroes[2] || likes[heroes[2]] == heroes[1]) team_liking++;
        if (likes[heroes[3]] == heroes[4] || likes[heroes[4]] == heroes[3]) team_liking++;
        if (likes[heroes[5]] == heroes[6] || likes[heroes[6]] == heroes[5]) team_liking++;

        if (diff < min_diff || (diff == min_diff && team_liking > max_liking)) {
            min_diff = diff;
            max_liking = team_liking;
        }
    } while (next_permutation(heroes.begin(), heroes.end()));

    cout << min_diff << " " << max_liking << endl;

    return 0;
}