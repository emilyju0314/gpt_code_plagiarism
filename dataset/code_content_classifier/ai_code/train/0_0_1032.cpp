#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
    int m, c, n;
    while (true) {
        cin >> m >> c >> n;
        if (m == 0 && c == 0 && n == 0) {
            break;
        }

        vector<queue<int>> desks(m);
        vector<int> shelf;
        int cost = 0;

        for (int i = 0; i < n; i++) {
            int ki;
            cin >> ki;

            for (int j = 0; j < ki; j++) {
                int book;
                cin >> book;

                bool found = false;
                for (int k = 0; k < m; k++) {
                    if (!desks[k].empty() && desks[k].front() == book) {
                        found = true;
                        desks[k].pop();
                        break;
                    }
                }

                if (!found && find(shelf.begin(), shelf.end(), book) != shelf.end()) {
                    shelf.erase(remove(shelf.begin(), shelf.end(), book), shelf.end());
                    cost += 1;
                } else {
                    cost += m + 1;
                }

                if (shelf.size() < c) {
                    shelf.push_back(book);
                } else {
                    int desk_idx = -1;
                    for (int k = 0; k < m; k++) {
                        if (desks[k].empty()) {
                            desk_idx = k;
                            break;
                        }
                    }

                    if (desk_idx == -1) {
                        int least_recently_used = desks[0].front();
                        int idx = 0;
                        desks[0].pop();
                        for (int k = 1; k < m; k++) {
                            if (desks[k].front() < least_recently_used) {
                                least_recently_used = desks[k].front();
                                idx = k;
                            }
                            desks[k].pop();
                        }
                        shelf.push_back(least_recently_used);
                        cost += m;
                    } else {
                        shelf.push_back(desks[desk_idx].front());
                        desks[desk_idx].pop();
                    }
                }

                desks[0].push(book);
                cost += 1;
            }
        }

        cout << cost << endl;
    }

    return 0;
}