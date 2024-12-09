#include <iostream>
#include <vector>

using namespace std;

struct Tree {
    int x, h, l, r;
};

struct Mushroom {
    int x, power;
};

int main() {
    int n, m;
    cin >> n >> m;

    vector<Tree> trees(n);
    vector<Mushroom> mushrooms(m);

    for (int i = 0; i < n; i++) {
        cin >> trees[i].x >> trees[i].h >> trees[i].l >> trees[i].r;
    }

    for (int i = 0; i < m; i++) {
        cin >> mushrooms[i].x >> mushrooms[i].power;
    }

    double total_expectation = 0;

    for (int i = 0; i < m; i++) {
        double mushroom_probability = 1.0;
        
        for (int j = 0; j < n; j++) {
            double prob_left = trees[j].l / 100.0;
            double prob_right = trees[j].r / 100.0;
            double prob_stay = 1 - prob_left - prob_right;
            
            double survival_probability = 0;
            if (mushrooms[i].x < trees[j].x - trees[j].h) {
                survival_probability = prob_left;
            } else if (mushrooms[i].x > trees[j].x + trees[j].h) {
                survival_probability = prob_right;
            } else {
                survival_probability = prob_stay;
            }

            mushroom_probability *= (1 - survival_probability);
        }

        total_expectation += mushrooms[i].power * (1 - mushroom_probability);
    }

    cout << fixed << setprecision(10) << total_expectation << endl;

    return 0;
}